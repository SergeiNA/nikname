#include "radixTrie.h"

#include <algorithm>
#include <iomanip>

using namespace std::string_literals;

const wchar_t stop = 0x26d2; // 26d2 d4


[[maybe_unused]] const wchar_t tabul = 0x0009;

const wchar_t box_curr_con = 0x2560; // current and continue
const wchar_t box_cont = 0x2551; // continue
const wchar_t box_curr_end = 0x255A; // current and end

const wchar_t sckull = 0x2620;
const wchar_t rTriangle = 0x25B8;
[[maybe_unused]]const wchar_t lTriangle = 0x25C2;

const wchar_t dbigTriangle = 0x2B55;

void decor_line(std::wostream& os){
        size_t count = 20;
        for (size_t i = 0; i < count; i++)
        {
            os<<(wchar_t)0x2583<<L' ';
        }
        os<<std::endl;
}

bool Trie::Insert(const std::wstring& rhs){
        try
        {
            if(rhs.empty())
                return false;
            return insert_(rhs,root);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
}

bool Trie::Find(std::wstring_view rhs) const {
        if (rhs.empty())
            return false;
        return find_(rhs,root);
}

void Trie::GetNicknames (std::wostream& os) const{
         if (!root)
            os << L""<<std::endl;
        os<<L"ᛈᚱᛁᚾᛏ ᚾᚨᛗᛖᛋ ᚨᚾᛞ ᚾᛁᚲᚴᚾᚨᛗᛖᛋ"<<std::endl;
        decor_line(os);
        get_nicks(os,root);
        decor_line(os);
        os<<std::endl;
}

void Trie::Print(std::wostream& os)const {
        if(!root)
            os << L""<<std::endl;

        os<<L"ᛞᛁᛋᛈᛚᚨᚤ ᚨᛚᛚ ᛏᚱᛖᛖ ᛒᚱᚢᚾᚲᚺᛖᛋ"<<std::endl;
        decor_line(os);
        print_node(os,root);
        decor_line(os);
        os<<std::endl;
}

void Trie::print_node(std::wostream& os, 
                    const NodePtr& root,
                    bool isLast,
                    std::vector<bool> pprint) const{
    if(!root)
        return;
    if(root->Lable.empty())
        os<<dbigTriangle<<std::endl;
    else{
        for(auto p:pprint)
            os<<L' '<<(p ? box_cont:L' ');

        pprint.push_back(!isLast);

        os<<L' '<<(isLast ? box_curr_end: box_curr_con);

        os<<rTriangle<<root->Lable<<L' ';
        if(root->isEnd)
            os<<stop;
        os<<std::endl;
    }
    
    if(root->childs.empty())
        return;

    for(auto itr = root->childs.cbegin(); itr!=root->childs.cend(); ++itr){
        bool is_Last = std::next(itr) == root->childs.cend();
        print_node(os,itr->second,is_Last,pprint);
    }
}

void Trie::get_nicks(std::wostream& os, 
                    const NodePtr& root, 
                    const std::wstring& prefix) const{
    if(!root)
        return;
    
    if((!root->Lable.empty()) && root->isEnd){
        os<<prefix<<root->Lable
            <<std::setw(10)
            <<std::setfill(L'.')
            <<sckull<<L' '
            <<prefix
            <<root->Lable.at(0)
            <<sckull<<std::endl;
        if(root->childs.empty())
            return;
    }
    for(const auto& n:root->childs)
        get_nicks(os,n.second,prefix+root->Lable);
    return;
}

bool Trie::find_(std::wstring_view rhs, const NodePtr& root) const {
    if(!root)
        return false;

    if(root->Lable.empty()){
        if(auto elem = root->childs.find(rhs[0]); 
            elem==end(root->childs))
            return false;
        else
            return find_(rhs,elem->second);           
    }

    auto [first, second] = std::mismatch(begin(rhs), end(rhs), begin(root->Lable));

    if(first == end(rhs)
       && second==end(root->Lable)
       && root->isEnd)
        return true;

    if(first != end(rhs) && second==end(root->Lable)){
        if(auto elem = root->childs.find(*first); elem!=end(root->childs)){
            return find_(std::wstring(first,end(rhs)),elem->second);
        }
        return false;
    }
    return false;
}

bool Trie::insert_(std::wstring_view rhs,NodePtr& root){

    if (!root){
        root = std::make_unique<Node>(rhs);
        return true;
    }
    if (root->Lable.empty()){
        auto res = root->childs.find(rhs.at(0));
        if (res != end(root->childs))
            return insert_(rhs, res->second);
        else
            root->childs[rhs.at(0)] = std::make_unique<Node>(std::wstring(rhs));
        return true;
    }

    auto [first, second] = std::mismatch(begin(rhs), end(rhs), begin(root->Lable));
    
    if (first != end(rhs) && second != end(root->Lable))
    {
        wchar_t rootIndx = *second;
        auto futureRoot = std::make_unique<Node>(std::wstring(begin(root->Lable),second));
        root->Lable = std::wstring(second,end(root->Lable));
        futureRoot->childs[rootIndx] = std::move(root);
        futureRoot->childs[*first] = std::make_unique<Node>(std::wstring(first,end(rhs)));
        root=std::move(futureRoot);
        root->isEnd=false;
        return true;
    }
    
    if (first == end(rhs) && second != end(root->Lable)){
        if (auto res = root->childs.find(*second); res != end(root->childs))
            return insert_(std::wstring(second, end(root->Lable)), res->second);
        else{
            wchar_t indx = *second;
            auto futureRoot = std::make_unique<Node>(rhs);;
            root->Lable = std::wstring(second, end(root->Lable));
            futureRoot->childs[indx] = std::move(root);
            root = std::move(futureRoot);
        }
        return true;
    }
    
    if (second == end(root->Lable) && first != end(rhs)){
        auto res = root->childs.find(*first);
        if (res != end(root->childs)){
            return insert_(std::wstring(first, end(rhs)), res->second);
        }
        else
            root->childs[*first] = std::make_unique<Node>(std::wstring(first, end(rhs)));
        return true;
    }
    
    if (first == begin(rhs) && second == begin(root->Lable)){
        auto futureRoot = std::make_unique<Node>(false);
        futureRoot->childs[root->Lable[0]] = std::move(root);
        futureRoot->childs[rhs[0]] = std::make_unique<Node>(std::wstring(rhs));
        root = std::move(futureRoot);
        return true;
    }
    if(!root->isEnd){
        root->isEnd=true;
        return true;
    }
    return false;
}