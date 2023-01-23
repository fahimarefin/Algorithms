#include<bits/stdc++.h>
using namespace std;
class HuffmanCodes{
    class NewNode{
    public:
        char data;
        size_t freq;
        NewNode* left;
        NewNode* right;
        NewNode(char d,size_t f){
            this->data=d;
            this->freq=f;
            left=NULL;
            right=NULL;
        }
        ~NewNode(){
            delete left;
            delete right;
        }
    };
    class Comapre{
    public:
        bool operator()(NewNode* left,NewNode *right){
        if(left->freq>right->freq){
                return true;
            }else{
                return false;
            }
        }
    };
    NewNode *top;
    void print(NewNode *root,string str){
        if(root==NULL){
            return;
        }
        if(root->data=='&'){
            print(root->left,str+"0");
            print(root->right,str+"1");
        }
        if(root->data!='&'){
            cout<<root->data<<":"<<str<<"\n";
            print(root->left,str+"0");
            print(root->right,str+"1");

        }
    }

public:
    HuffmanCodes(){
    };
    ~HuffmanCodes(){
        delete top;
    }
    void generate_Huffman_tree(vector<char>&data,vector<size_t>& freq,size_t size){
        NewNode *left;
        NewNode *right;
        priority_queue<NewNode*,vector<NewNode*>,Comapre>minHeap;
        for(size_t i=0; i<size; i++){
            minHeap.push(new NewNode(data[i],freq[i]));
        }
        while (minHeap.size()!=1){
            left=minHeap.top();
            minHeap.pop();
            right=minHeap.top();
            minHeap.pop();
            top=new NewNode('&',left->freq+right->freq);
            top->left=left;
            top->right=right;
            minHeap.push(top);
        }
        print(minHeap.top(),"");
    }
};

int main() {
    int n,f;
    char ch;
    vector<char>data;
    vector<size_t>freq;
    cout<<"Enter how many number you want to pick:"<<endl;
    cin>>n;
    cout<<"Input The Character Variables:"<<endl;
    for(int i=0; i<n; i++){
        cin>>ch;
        data.insert(data.end(),ch);
    }
    cout<<"Enter the frequencies:"<<endl;
    for(int i=0; i<n; i++){
        cin>>f;
        freq.insert(freq.end(),f);
    }
    HuffmanCodes obj1;
    size_t size=data.size();

    obj1.generate_Huffman_tree(data,freq,size);

}

