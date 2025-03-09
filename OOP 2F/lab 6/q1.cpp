#include <iostream>
using namespace std;

class Message{
    private:
    string text;
    public:
    Message(string t = " "): text(t){}
    virtual string toString() const{
        return text;
    }
    void setString(string newtext){
        text=newtext;
    }
    bool ContainsKeyword(const Message& messageObject, const string& keyword){
        return messageObject.toString().find(keyword) != string ::npos;
    }
    string encoding(){
        string idk = text;
        for(char &c : idk){
            if(c>='A' && c<='Z'){
                if(c=='Z'){
                    c='A';
                }else
                c=c+1;
            }else if(c>='a' && c<='z'){
                if(c=='z'){
                    c='a';
                }else 
                c=c+1;
            }
            
        }
    setString(idk);
    return idk;
    }
};

class SMS:public Message{
    private:
    string recipientContactNo;
    public:
    SMS(string num= " ", string contact=" "): recipientContactNo(num), Message(contact){}
    string getContact() const{
        return recipientContactNo;
    }
    void setContact(string contact){
        recipientContactNo = contact;
    }
    string toString() const override{
        return "To: " + getContact() + "\nMessage: " + Message::toString();
    }
};

class Email : public Message {
    private: 
    string sender, receiver, subject;
    public:
    Email(string s="",string r="",string sub="",string text1=""):sender(s),receiver (r),subject(sub),Message(text1){}
     
    string getSender() const{
        return sender;
    }
    string getReceiver() const{
        return receiver;
    }
    string getSubject() const{
        return subject;
    }
    void setSender(string newS){
        sender=newS;
    }
    void setReceiver(string newR){
        receiver=newR;
    }
    void setSubject(string newSubject){
       subject=newSubject;
    }
    string toString() const override{
        return "\nFrom :" + getSender() + 
        "\nTo: " + getReceiver() +
        "\nSubject : " + getSubject() +
        "\nMessage : " + Message::toString();
    }
};

int main() {
    SMS s;
    Email e;
    string k;
    Message m;
    e.setString("message 123 hello");
    e.setSender("Aamna"); e.setReceiver("Hammad"); e.setSubject("idiots");
    cout << e.toString() << endl;
    cout << "Enter keyword to search in Message" << endl;
    getline(cin,k);
    if(e.ContainsKeyword(e,k)){
        cout << "Keyword " << k << " found in message\n";
    }else
    cout << "Keyword " << k << " not found in message\n";
    cout << "Your encoded message is: " << e.encoding();
    cout<< e.toString();
    
}
