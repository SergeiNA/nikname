#include <vector>
#include <memory>
#include <iostream>
#include <unordered_map>

class Trie{
    struct Node;
    typedef std::unique_ptr<Node> NodePtr;

    struct Node{
        Node() : isEnd(true){};
        Node(bool isEnd_) : isEnd(isEnd_){};
        Node(const std::wstring &str) : Lable(str), isEnd(true) {}
        Node(std::wstring &&str) : Lable(str), isEnd(true) {}
        Node(std::wstring_view str) : Lable(str), isEnd(true) {}

        std::unordered_map<wchar_t, NodePtr> childs;
        std::wstring Lable;
        bool isEnd;
    };

public:
    Trie():root(nullptr) {};
    bool Insert(const std::wstring& rhs);
    bool Find(std::wstring_view rhs) const;
    void GetNicknames (std::wostream& os = std::wcout) const;
    void Print(std::wostream& os = std::wcout)const;

private:
    void print_node(std::wostream& os, 
                    const NodePtr& root,
                    bool isLast = true,
                    std::vector<bool> pprint ={}) const;
    
    void get_nicks(std::wostream& os, 
                    const NodePtr& root, 
                    const std::wstring& prefix={}) const;

    bool find_(std::wstring_view rhs, const NodePtr& root) const;

    bool insert_(std::wstring_view rhs,NodePtr& root);

private:
    NodePtr root;
};