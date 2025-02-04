#include<bits/stdc++.h>
using namespace std;
//Trie implementation
//implementing the trie node class

class TrieNode{
    public:
    //node contains data,pointers to its children & is it terminal(bool)
    char data;
    TrieNode* children[26];
    bool isTerminal;

    //constructor for root node
    // TrieNode(){
    //     data='\0';
    //     for(int i=0;i<26;i++){
    //         children[i]=NULL;
    //     }
    //     isTerminal=false;
    // }

    //constructor for rest of the nodes
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};

//implementing the trie class
class Trie{
    //it contains pointer to root
    public:
    TrieNode*root;

    //constructor for Trie, initializing root
    Trie(){
        root=new TrieNode('\0');
    }

    //insertion function for Trie-->based on recursion
    void insertUtil(TrieNode*root,string word){
        //base case
        if(word.length()==0){
            root->isTerminal=true; //mark that its the last char in word
            return;
        }
        

        int index=word[0]-'A'; //getting position
        TrieNode*child;
        //present
        if(root->children[index]!=NULL){
            child=root->children[index];   //set child to char at index position in word
        }
        //absent
        else{
            //create child and set it as children of the root
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        //recursion call-->follow the provcedure for selected/created child of root with next ch in word
        insertUtil(child,word.substr(1)); //substr->passes all ch to its right of ch by 1
    }

    void insert(string word){
        insertUtil(root,word);
        cout<<word<<" inserted successfully in Trie."<<endl;
    }

    //searching in trie-->using recursion and a util function
    bool searchUtil(TrieNode*root,string word){
        //base case
        if(word.length()==0){
            if(root->isTerminal==true){
                return true; //last ch of word
            }
            else{
                return false;
            }  
        }

        //get index 
        int index=word[0]-'A';
        TrieNode*child;
        
        //absent
        if(root->children[index]==NULL){
            return false;
        }
        //present
        else{
            child=root->children[index];
        }

        //recursive call for child
        return searchUtil(child,word.substr(1));

    }

    bool search(string word){
        return searchUtil(root,word);
    }

    //removing from a word trie using recursion and a util function
    void removeUtil(TrieNode* root,string word){
        //base case
        if(word.length()==0){
            root->isTerminal=false;   //make terminal false, so its not an end ch anymore
            return;
        }

        int index=word[0]-'A';
        TrieNode*child;
        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        //absent
        else{
            return;
        }
        //recurisive call for child
        removeUtil(child,word.substr(1));
    }

    void remove(string word){
        removeUtil(root,word);
        cout<<"Removed word :"<<word<<" from trie successfully."<<endl;
    }

    //return if there are words starting with given prefix using recursion & a utility function
    bool startsWithUtil(TrieNode*root,string word){
        //base case
        if(word.length()==0){
            return true;
        }

        //get index
        int index=word[0]-'a';
        TrieNode*child;

        //present
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        //absent
        else{
            return false;
        }

        //recursive calls for child
        return startsWithUtil(child,word.substr(1));
    }

    bool startsWith(string word){
        return startsWithUtil(root,word);
    }
    
};



int main(){
    //reating new trie
    Trie* t=new Trie();

    t->insert("PRATIK");
    t->insert("JITENDRA");
    t->insert("PATIL");
    t->insert("SWATI");

    if(t->search("PRATIK")){
        cout<<"PRATIK present in trie."<<endl;
    }
    else{
        cout<<"PRATIK absent in trie."<<endl;
    }

    if(t->search("PRANALI")){
        cout<<"PRANALI present in trie."<<endl;
    }
    else{
        cout<<"PRANALI absent in trie."<<endl;
    }

    t->remove("SWATI");

    if(t->search("SWATI")){
        cout<<"SWATI present in trie."<<endl;
    }
    else{
        cout<<"SWATI absent in trie."<<endl;
    }

    return 0;
}