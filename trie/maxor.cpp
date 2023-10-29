// ques -> https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

class Solution {
struct trienode
{   
    int isno=-1;
    trienode*child[2];
    trienode(){
        for(int i=0;i<2;i++){
            child[i]=NULL;
        }
    }
};
trienode *root=new trienode();
void buildtrie(string k,int no){
    trienode*curr=root;
    int ind;
    for(int i=0;i<k.length();i++){
        ind=k[i]-'0';
        if(curr->child[ind]==NULL){
            curr->child[ind]=new trienode();
        }
            curr=curr->child[ind];
    }
    curr->isno=no;
    // cout << no << endl;
    // cout << curr->isno << endl;
}
int search(string k){
    trienode*curr=root;
    int ind;
    for(int i=0;i<k.size();i++){
        ind=k[i]-'0';
        if(ind==0){
            ind=1;
        }
        else{
            ind=0;
        }
        if(curr->child[ind]){
            curr=curr->child[ind];
        }
        else{
            curr=curr->child[!ind];
        }
    }
    cout << curr->isno << endl;
    return curr->isno;
}
string makestring(int no,int size){
    string s="";
    while(no>0){
        int a=no%2;
        if(a==1){
        s.push_back('1');}
        else{
            s.push_back('0');
        }
        no=no/2;
    }
    int k=s.size();
    for(int i=k;i<size;i++){
        s.push_back('0');
    }
    reverse(s.begin(),s.end());
    // cout << s << endl;
    return s;
}
void inserttotrie(int no,int size){
    string s="";
    int temp=no;
    while(no>0){
        char c=no%2+'0';
        s.push_back(c);
        no=no/2;
    }
    int k=s.size();
    for(int i=k;i<size;i++){
        s.push_back('0');
    }
    reverse(s.begin(),s.end());
    // cout << s << endl;
    buildtrie(s,temp);
}
public:
    int findMaximumXOR(vector<int>& nums){
        int mx=*max_element(nums.begin(),nums.end());
        int ct=0;
        while(mx>0){
            ct++;
            mx/=2;
        }
        for(int i=0;i<nums.size();i++){
            inserttotrie(nums[i],ct);
        }
        int maxor=0;
        for(int i=0;i<nums.size();i++){
            maxor=max(maxor,nums[i]^search(makestring(nums[i],ct)) );
        }
        return maxor;
}
};


// not the best optimise accordingly 