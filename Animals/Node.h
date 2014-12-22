#pragma once
#include <string>
#include <iostream>
#include <cstdio>
#include <cstddef>

using namespace std;

bool yesOrNo(std::string question) {
    std::string res;
    cout << question << endl;
    getline(cin,res);
    while ( (res !="y") && (res!="n") ) {
        cout << "Please, type 'y' or 'n'\n" << question << endl;
        getline(cin,res);
    }
    return res=="y";
}


class Node {
public:
    virtual ~Node() {};
    virtual bool ask(Node** parent=nullptr)=0;
};

class Question : public Node {
public:
    const string text;
    Node* yes;
    Node* no;

    Question(string text_, Node* y, Node* n)
        : text(text_), yes(y), no(n) {};
    virtual ~Question() {
        delete yes;
        delete no;
    }

    virtual bool ask(Node** parent) {
        if (yesOrNo(text)) {
            return yes->ask(&yes);
        } else {
            return no->ask(&no);
        }
    }
};

class Answer : public Node {
public:
    const string text;

    Answer(string text_) : text(text_) {};
    virtual ~Answer() {};

    virtual bool ask(Node** parent) {
        if (yesOrNo("It is "+text+"?") ) {
            cout << "Hooray! I've guessed\n";
        } else {
            string answer;
            string question;
            cout<<"Who is it?"<<endl;
            getline(cin,answer);
            cout<<"what is true for "<<answer<<" and is false for "<<text << endl;
            getline(cin,question);
            *parent=new Question(
                question,
                new Answer(answer),
                this
            );
        }
        return yesOrNo("Play again?\n");
    }
};
