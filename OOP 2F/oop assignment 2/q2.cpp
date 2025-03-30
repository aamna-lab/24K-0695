//24K-0695 Aamna_Rizwan Q2
#include <iostream>
using namespace std;

class Ghost {
protected:
    string worker;
    int scareLevel;
public:
    Ghost(string n = "", int level = 0) : worker(n), scareLevel(level) {}
    virtual void haunting() {
        cout << "Ghost " << worker << " haunting with scare level of " << scareLevel << endl;
    }
    friend ostream& operator<<(ostream& os, const Ghost& g) {
        os << "Ghost played by: " << g.worker << " | Scare Level: " << g.scareLevel;
        return os;
    }
    Ghost* operator+(const Ghost& other) {
        return new Ghost(worker + " & " + other.worker, scareLevel + other.scareLevel);
    }
    int getScare() { return scareLevel; }
    virtual ~Ghost() {}
};

class Poltergeist : public virtual Ghost {
public:
    Poltergeist(string n = "", int level = 0) : Ghost(n, level) {}
    void haunting() override {
        cout << "Poltergeist moving objects with scare level of " << scareLevel << endl;
    }
};

class Banshee : public virtual Ghost {
public:
    Banshee(string n = "", int level = 0) : Ghost(n, level) {}
    void haunting() override {
        cout << "Banshee screaming loudly with scare level of " << scareLevel << endl;
    }
};

class ShadowGhost : public virtual Ghost {
public:
    ShadowGhost(string n = "", int level = 0) : Ghost(n, level) {}
    void haunting() override {
        cout << "Shadow Ghost whispering creepily with scare level of " << scareLevel << endl;
    }
};

class ShadowPoltergeist : public ShadowGhost, public Poltergeist {
public:
    ShadowPoltergeist(string n = "", int level = 0)  
        : Ghost(n, level), ShadowGhost(n, level), Poltergeist(n, level) {}
    void haunting() override {
        int totalScare = ShadowGhost::scareLevel + Poltergeist::scareLevel;
        cout << "Shadow Poltergeist whispering creepily and moving objects with scare level of " 
             << totalScare << endl;
    }
};

class HauntedHouse {
protected:
    string name;
    Ghost* ghosts[5];  
    int ghostCount;
public:
    HauntedHouse(string n) : name(n), ghostCount(0) {}
    void addGhost(Ghost* g) {
        if (ghostCount < 5) {
            ghosts[ghostCount++] = g;
        } else {
            cout << "No space for more ghosts in " << name << "!\n";
        }
    }
    Ghost** getGhosts() { return ghosts; }
    int getGhostCount() { return ghostCount; }
    string getName() { return name; }
    ~HauntedHouse() {
        for (int i = 0; i < ghostCount; i++) delete ghosts[i];
    }
};

class Visitor {
protected:
    string visitorName;
    int bravery; 
public:
    Visitor(string n = "", int b = 0) : visitorName(n), bravery(b) {}
    void visitHauntedHouse(Ghost* g) {  
        int level = g->getScare();
        if ((bravery <= 4 && level <= 4) || (bravery >= 5 && bravery <= 7 && level >= 5 && level <= 7) || (bravery >= 8 && level >= 8)) {
            cout << visitorName << " has a shaky voice.\n";
        } else if (level < bravery) {
            cout << visitorName << " is laughing and taunting the ghost.\n";
        } else {
            cout << visitorName << " is screaming or running away!\n";
        }
    }
    string getName() { return visitorName; }
};

void Visit(Visitor* vis, HauntedHouse& house) {
    cout << "Visitors entering " << house.getName() << "...\n";

    for (int i = 0; i < 3; i++) {
        cout << vis[i].getName() << " is visiting the haunted house.\n";
        for (int j = 0; j < house.getGhostCount(); j++) {
            vis[i].visitHauntedHouse(house.getGhosts()[j]);
        }
    }
}

int main() {
    HauntedHouse h1("Spooky Mansion");
    HauntedHouse h2("Creepy Villa");
    HauntedHouse h3("Eerie House");
    h1.addGhost(new Poltergeist("Haniya", 6));
    h1.addGhost(new Banshee("Sarah", 8));
    h2.addGhost(new ShadowGhost("Hassaan", 5));
    h2.addGhost(new ShadowPoltergeist("Spirit", 7));
    h3.addGhost(new Banshee("Naheed", 9));
    h3.addGhost(new Poltergeist("Yousuf", 4));
    Visitor v[3] = { Visitor("Aamna", 4), Visitor("Hammad", 8), Visitor("Ilsa", 6) };
    Visit(v, h1);
    Visit(v, h2);
    Visit(v, h3);
}
