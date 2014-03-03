#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include <set>

class Folder;

class Message {
		friend void swap(Message&, Message&);
		friend class Folder; 
public:
	explicit Message(const std::string &str = ""):contents(str) { }
	Message(const Message&);
	Message& operator=(const MEssage &);
	~Message();
	Message(Message&&);
	Message& operator=(Message&&);

	void save(Folder&);
	void remove(Folder&);
	void debug_print();

private:
	std::string contents;
	std::set<Folder*> folders;

	
};

#endif /*FOLDER_H*/