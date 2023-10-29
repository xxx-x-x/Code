#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
//首先我们要创建huffmanTree

//Node
class HuffmanNode{
    public:
    HuffmanNode(){
        data = ' ';
    }
    HuffmanNode(char da,int we):data(da),weight(we){}
    HuffmanNode(HuffmanNode &n1):lchild(n1.lchild),rchild(n1.rchild),data(n1.data),weight(n1.weight){}
    void operator=(HuffmanNode* h2){
        data = h2->data;
        lchild = h2->lchild;
        rchild = h2->rchild;
        weight = h2->weight;
    }
    HuffmanNode *lchild;//左孩子
    HuffmanNode *rchild;//右孩子
    char data;//存储
    int weight;//权重
};
//Tree
class HuffmanTree{
    public:
    HuffmanNode *root;//树根
    map<char,int> weightmap;//存储权重

    void getWeight(string s1);//给一个字符串，统计每个字符出现的权重
    void creatHuffmanTree();//创建树
    void preOrder(HuffmanNode* r1);//先序遍历
};
//function object
class HuffmanNodeCompare{
    public:
    bool operator()(const HuffmanNode* a,const HuffmanNode* b){
        return a->weight < b->weight;
    }
};
void HuffmanTree::getWeight(string s1){
    for(int i=0;i<s1.size();i++){
        this->weightmap[s1[i]]++;
    }
}
void HuffmanTree::creatHuffmanTree(){
    vector<HuffmanNode*> v1;//我们创建容器存储节点
    map<char,int>::iterator iter = weightmap.begin();//创建迭代器来遍历map
    for(;iter!=weightmap.end();iter++){
        auto temp = new HuffmanNode();
        temp->data = iter->first;
        temp->weight = iter->second;
        v1.push_back(temp);
    }//循环结束后，容器v1 已经存好了所有节点的值和权重。我们需要判断是否为空的
    while(v1.size()!=1){
        //首先进行一个从小到大的排序
        sort(v1.begin(),v1.end(),HuffmanNodeCompare());
        //排序后，最前面两个就是最小的两个，将两个节点合并为一个节点，我们需要有拷贝构造函数，重载赋值运算符
        HuffmanNode *h1 = new HuffmanNode();
        //我们要被合并的两个需要拿出来，然后挂到新节点下面（不能直接指，容器内删除时，会直接删掉）
        //我们是创建新的地址空间，然后将旧的拷贝到新的，不是拿新指针指向旧地址空间
        HuffmanNode *n1 = new HuffmanNode();
        HuffmanNode *n2 = new HuffmanNode();
        //拷贝过去
        n1 = v1[0];
        n2 = v1[1];
        //新节点权值
        h1->weight = n1->weight + n2->weight;
        //开始创建树，小的放左边，大的放右边
        h1->lchild = n1;
        h1->rchild = n2;
        //我们节点容器里面要把这两个删掉了
        v1.erase(v1.begin(),v1.begin()+2);
        //把新创建的节点放入到节点容器中
        v1.push_back(h1);
        //不需要进行排序，因为在下一轮循环中，会重新排序的
    }
    this->root = v1[0];
}
//先序遍历，固定代码需要牢记
void HuffmanTree::preOrder(HuffmanNode *r1){
    if(root == nullptr){
        return;
    }else{
        cout << " " << r1->weight << " ";
        preOrder(r1->lchild);
        preOrder(r1->rchild);
    }
}

//我们需要创建编码，需要传入存储编码的编码集（自己起的），需要传入树根
//编码集应存储字符和 对应编码，是键值对，类似于map类型的
void getCode(vector<pair<char,string>> code,string *temp,HuffmanNode *root){
    //如果左子树和右子树都是空的，也就是说我们遇到了叶子节点，我们需要创建并且放入到数组中
    if(root->lchild == nullptr && root->rchild == nullptr){
        //创建键值对
        pair<char,string> p1;
        //该放的放进去
        p1.first = root->data;
        p1.second = *temp;
        //键值对 放进编码集
        code.push_back(p1);
        temp->pop_back();
        return;
    }
    //先序是中左右，如果不是叶子节点，那么往左走，左0右1
    if(root->lchild!=nullptr){
        temp->push_back('0');
        getCode(code,temp,root->lchild);
    }
    //不能往左，再往右走，左0右1
    if(root->rchild!=nullptr){
        temp->push_back('1');
        getCode(code,temp,root->rchild);
    }
    temp->pop_back();
}
int main(){
    //创建huffman树
    HuffmanTree h1;
    //创建字符串
    string s1;
    //输入字符串
    cin >> s1;
    //给huffman树创建权重
    h1.getWeight(s1);
    //h1根据权重创建huffman树
    h1.creatHuffmanTree();
    //先序遍历
    h1.preOrder(h1.root);
}