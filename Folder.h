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
	std::set<Folder*> folders; // Folders that have this message

	void add_to_Folders(cosnt Message&);

	void remove_from_Folders();
	// used by Folder class to add self to this Message's set of Folder's
    void addFldr(Folder *f) { folders.insert(f); }
    void remFldr(Folder *f) { folders.erase(f); }
};

// declaration for swap should be in the same header as Message itself
void swap(Message&, Message&);

class Folder {
	friend void swap(Message&, Message&);
	friend class Message;
public:
    ~Folder(); // remove self from Messages in msgs
    Folder(const Folder&); // add new folder to each Message in msgs
    Folder& operator=(const Folder&); // delete Folder from lhs messages
                                      // add Folder to rhs messages
    Folder(Folder&&);   // move Messages to this Folder 
    Folder& operator=(Folder&&); // delete Folder from lhs messages
                                 // add Folder to rhs messages

    Folder() = default; // defaults ok

    void save(Message&);   // add this message to folder
    void remove(Message&); // remove this message from this folder
    
    void debug_print(); // print contents and it's list of Folders, 
private:
    std::set<Message*> msgs;  // messages in this folder

    void add_to_Messages(const Folder&);// add this Folder to each Message
    void remove_from_Msgs();     // remove this Folder from each Message
    void addMsg(Message *m) { msgs.insert(m); }
    void remMsg(Message *m) { msgs.erase(m); }
	void move_Messages(Folder*); // move Message pointers to point to this Folder
};


#endif /*FOLDER_H*/