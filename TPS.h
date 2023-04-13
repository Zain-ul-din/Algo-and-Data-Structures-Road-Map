#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Stack.h";
#include "queue.h";
#include "doubly_linkedlist.h";

using namespace std;

#define DEBUG(X) cout << #X << ": " << X << "\n";

class TPS;

class DocumentMetaData
{
public:
	string userName;
	string docName;
	int currVersion;
	string currDocumentName;
	LinkedList<int> versions;

	void initVersion(bool cacheText = false)
	{
		if (!versions.empty())
		{
			currVersion = 0;
		}
		else
		{
			string fileName;

			currVersion = versions.end()->data + 1;
		}
	}

	void readDocument(int version)
	{
		ifstream in;
		currDocumentName = version + "_" + userName + "_" + docName;
		in.open(currDocumentName, ios::in);
		if (in.fail()) return;

		if (in.peek() == ifstream::traits_type::eof())
			return;

		std::stringstream bufferReader;
		bufferReader << in.rdbuf();
		tps->addText(bufferReader.str());
	}

	TPS* tps;
};


class Document
{
public:
	string docmentName;
	string versionControlFile;
	DLinkedList<DocumentMetaData> documentsMetaData;

	Document()
	{
		versionControlFile = "VERSION_CONTROL_" + docmentName;
	}

	void init()
	{
		ifstream in;
		in.open(versionControlFile, ios::in);
		if (in.fail()) return;

		if (in.peek() == ifstream::traits_type::eof())
			return;

		string bufferReader = "";

		// format: userName: fileVersions,....
		while (getline(in, bufferReader))
		{
			// format: userName: fileVersions,....
			istringstream iss(bufferReader);
			string userName;
			getline(iss, userName, ':');

			DocumentMetaData docMeta;

			docMeta.docName = docmentName;
			docMeta.userName = userName;

			string versionsStr;
			getline(iss, versionsStr);

			istringstream viss(versionsStr);
			string versionStr;
			while (std::getline(viss, versionStr, ','))
			{
				int version = std::stoi(versionStr);
				docMeta.versions.push(version);
			}

			docMeta.initVersion();

			documentsMetaData.Push(docMeta);
		}
	}
};


class TPS
{
public:

	/*
		PART A
	*/

	TPS (): userAuth ("user") {
		undo_stack.push("");
	}

	void createNewDocument(string documentName)
	{
		if (documentExists(documentName)) return;

		this->currDocumentName = documentName;

		ofstream out;
		out.open(this->currDocumentName, ios::out);
		if (out.fail()) return;
		out << "";
		out.close();

		createVersionControlFile("VERSION_CONTROL_" + this->currDocumentName);
	}
	
	void addText(std::string text)
	{
		for (int i = 0; i < text.length(); i += 1)
			handleInputArgument(text[i]);
	}

	std::string getDocumentText(std::string documentName)
	{
		if (document != nullptr)
		{
			Node<DocumentMetaData>* doc = document->documentsMetaData.Find([&](DocumentMetaData data)->bool {
				return data.userName == currUser;
			});

			return doc->data.tps->getDocumentText(doc->data.currDocumentName);
		}

		return this->documentText;
	}

	std::string readDocument(std::string documentName)
	{
		this->currDocumentName = documentName;
		this->documentText = TPS::readText(documentName);
		undo_stack.push(documentText);

		return documentText;
	}

	~TPS()
	{
		redo_stack.clear();
		undo_stack.clear();
	}

	/*
		PART B
	*/

	bool documentExists(string documentName)
	{
		ifstream in (documentName);
		return in.good();
	}
	
	void addText(string text, string documentName, string user)
	{
		currUser = user;
		if (document == nullptr)
			document = new Document();
		
		Node<DocumentMetaData>* potentialUser = document->documentsMetaData.Find([&](DocumentMetaData data)->bool {
			return data.userName == currUser;
		});

		if (!potentialUser)
		{
			DocumentMetaData newDoc;
			newDoc.userName = currUser;
			newDoc.docName = documentName;
			newDoc.initVersion();

			document->documentsMetaData.Push(newDoc);
		}

		Node<DocumentMetaData>* doc = document->documentsMetaData.Find([&](DocumentMetaData data)->bool {
			return data.userName == currUser;
		});

		doc->data.tps.addText(text);
	}

private:

	string versionControlFile;
	string userAuth, currUser;
	string documentText;
	string currDocumentName;

	Stack<string> redo_stack, undo_stack;
	Queue<string> glitchQueue;

	Document* document;

	void saveText()
	{
		ofstream out;
		out.open(this->currDocumentName, ios::out);
		if (out.fail()) return;
		out << documentText;
		out.close();
	}
	
	static std::string readText(std::string documentName)
	{
		ifstream in;
		in.open(documentName, ios::in);
		if (in.fail()) return "";

		if (in.peek() == ifstream::traits_type::eof())
			return "";

		std::stringstream bufferReader;
		bufferReader << in.rdbuf();
		return bufferReader.str();
	}

	

	void perform_undo()
	{
		if (undo_stack.empty()) return;
		
		if (undo_stack.top()->data == documentText)
		{
			redo_stack.push(documentText);

			undo_stack.pop();
			documentText = undo_stack.top()->data;
		}
		else
		{
			documentText = undo_stack.top()->data;
		}

	}

	void perform_redo()
	{
		if (redo_stack.empty()) return;
		
		undo_stack.push(documentText);
		documentText = redo_stack.top()->data;
		glitchQueue.enqueue(documentText);
		redo_stack.pop();
	}

	void createVersionControlFile(string fileName)
	{
		this->versionControlFile = fileName;

		ofstream out;
		out.open(this->currDocumentName, ios::out);
		if (out.fail()) return;
		out << "";
		out.close();
	}

	void handleInputArgument(char argu)
	{
		switch (argu)
		{
			case '@': // undo
				perform_undo();
			break;
			case '#': // redo
				perform_redo();
			break;
			case '/': // add line break
				this->documentText += "\n";
			break;
			case '.': // save state
				this->documentText += argu;
				undo_stack.push(this->documentText);
			break;
			case '^': // restore glitch
				if (glitchQueue.empty()) return;
				this->documentText = glitchQueue.front()->data;
				glitchQueue.dequeue();
			break;
			default:
				this->documentText += argu;
			break;
		}
	}
};
