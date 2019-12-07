#define BOOST_TEST_MODULE main_test

#include "radixTrie.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(nickname_ru)

BOOST_AUTO_TEST_CASE(insert)
{
    Trie trie;
    BOOST_CHECK(trie.Insert(L"Астрономия"));
    BOOST_CHECK(trie.Insert(L"Астрономический"));
    BOOST_CHECK(trie.Insert(L"Астрофизика"));
    BOOST_CHECK(trie.Insert(L"Астронавт"));
    BOOST_CHECK(trie.Insert(L"Астероид"));
    BOOST_CHECK(trie.Insert(L"Космонавт"));
    BOOST_CHECK(trie.Insert(L"Космос"));
    BOOST_CHECK(trie.Insert(L"Космический"));
    BOOST_CHECK(trie.Insert(L"Космопорт"));

    
    BOOST_CHECK(!trie.Insert(L"Астрономия"));
    BOOST_CHECK(!trie.Insert(L"Астрономический"));
    BOOST_CHECK(!trie.Insert(L"Астрофизика"));
    BOOST_CHECK(!trie.Insert(L"Астронавт"));
    BOOST_CHECK(!trie.Insert(L"Астероид"));
    BOOST_CHECK(!trie.Insert(L"Космонавт"));
    BOOST_CHECK(!trie.Insert(L"Космос"));
    BOOST_CHECK(!trie.Insert(L"Космический"));
    BOOST_CHECK(!trie.Insert(L"Космопорт"));
}

BOOST_AUTO_TEST_CASE(find)
{
    Trie trie;
    BOOST_CHECK(trie.Insert(L"Астрономия"));
    BOOST_CHECK(trie.Insert(L"Астрономический"));
    BOOST_CHECK(trie.Insert(L"Астрофизика"));
    BOOST_CHECK(trie.Insert(L"Астронавт"));
    BOOST_CHECK(trie.Insert(L"Астероид"));
    BOOST_CHECK(trie.Insert(L"Космонавт"));
    BOOST_CHECK(trie.Insert(L"Космос"));
    BOOST_CHECK(trie.Insert(L"Космический"));
    BOOST_CHECK(trie.Insert(L"Космопорт"));
    
    BOOST_CHECK(trie.Find(L"Астрономия"));
    BOOST_CHECK(trie.Find(L"Астрономический"));
    BOOST_CHECK(trie.Find(L"Астрофизика"));
    BOOST_CHECK(trie.Find(L"Астронавт"));
    BOOST_CHECK(trie.Find(L"Астероид"));
    BOOST_CHECK(trie.Find(L"Космонавт"));
    BOOST_CHECK(trie.Find(L"Космос"));
    BOOST_CHECK(trie.Find(L"Космический"));
    BOOST_CHECK(trie.Find(L"Космопорт"));


    BOOST_CHECK(!trie.Find(L"Компот"));
    BOOST_CHECK(!trie.Find(L"Крокодил"));
    BOOST_CHECK(!trie.Find(L"Космапорт"));

    BOOST_CHECK(!trie.Find(L"Астро"));
    BOOST_CHECK(trie.Insert(L"Астро"));
    BOOST_CHECK(trie.Find(L"Астро"));
}

BOOST_AUTO_TEST_SUITE_END()