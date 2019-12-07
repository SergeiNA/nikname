#include "radixTrie.h"

#include <locale>
#include <codecvt>
#include <iostream>
#include <algorithm>

using namespace std::string_literals;

void Run(std::wistream& wis = std::wcin,
        std::wostream&  wos = std::wcout){

    const std::locale empty_locale;
    typedef std::codecvt_utf8<wchar_t> converter_type;
    const std::unique_ptr<converter_type> converter = std::make_unique<converter_type>();
    const std::locale utf8_locale = std::locale(empty_locale, converter.get());
    wos.sync_with_stdio(false);
    wos.imbue(utf8_locale);
    wis.imbue(utf8_locale);

    std::wstring line;
    Trie trie;
    while(wis&&(!wis.eof())){
        std::getline(wis,line);
        if(line.empty())
            break;
        trie.Insert(line);
    }
    trie.Print(wos);
    trie.GetNicknames(wos);
}

int main(){
    Run();
    return 0;
}

