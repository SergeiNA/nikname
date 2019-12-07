#define BOOST_TEST_MODULE main_test

#include "radixTrie.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(nickname_en)

BOOST_AUTO_TEST_CASE(insert)
{
    Trie trie;
    BOOST_CHECK(trie.Insert(L"facebook"));
    BOOST_CHECK(trie.Insert(L"face"));
    BOOST_CHECK(trie.Insert(L"facebooking"));
    BOOST_CHECK(trie.Insert(L"facetap"));
    BOOST_CHECK(trie.Insert(L"falcon"));
    BOOST_CHECK(trie.Insert(L"fashion"));
    BOOST_CHECK(trie.Insert(L"fasiliate"));
    BOOST_CHECK(trie.Insert(L"afacebook"));
    BOOST_CHECK(trie.Insert(L"aface"));
    BOOST_CHECK(trie.Insert(L"afacetap"));
    BOOST_CHECK(trie.Insert(L"afalcon"));
    
    BOOST_CHECK(!trie.Insert(L"facebook"));
    BOOST_CHECK(!trie.Insert(L"face"));
    BOOST_CHECK(!trie.Insert(L"facebooking"));
    BOOST_CHECK(!trie.Insert(L"facetap"));
    BOOST_CHECK(!trie.Insert(L"falcon"));
    BOOST_CHECK(!trie.Insert(L"fashion"));
    BOOST_CHECK(!trie.Insert(L"fasiliate"));
    BOOST_CHECK(!trie.Insert(L"afacebook"));
    BOOST_CHECK(!trie.Insert(L"aface"));
    BOOST_CHECK(!trie.Insert(L"afacetap"));
    BOOST_CHECK(!trie.Insert(L"afalcon"));
}

BOOST_AUTO_TEST_CASE(find)
{
    Trie trie;
    BOOST_CHECK(trie.Insert(L"facebook"));
    BOOST_CHECK(trie.Insert(L"face"));
    BOOST_CHECK(trie.Insert(L"facebooking"));
    BOOST_CHECK(trie.Insert(L"facetap"));
    BOOST_CHECK(trie.Insert(L"falcon"));
    BOOST_CHECK(trie.Insert(L"fashion"));
    BOOST_CHECK(trie.Insert(L"fasiliate"));
    BOOST_CHECK(trie.Insert(L"afacebook"));
    BOOST_CHECK(trie.Insert(L"aface"));
    BOOST_CHECK(trie.Insert(L"afacetap"));
    BOOST_CHECK(trie.Insert(L"afalcon"));
    
    BOOST_CHECK(trie.Find(L"facebook"));
    BOOST_CHECK(trie.Find(L"face"));
    BOOST_CHECK(trie.Find(L"facebooking"));
    BOOST_CHECK(trie.Find(L"facetap"));
    BOOST_CHECK(trie.Find(L"falcon"));
    BOOST_CHECK(trie.Find(L"fashion"));
    BOOST_CHECK(trie.Find(L"fasiliate"));
    BOOST_CHECK(trie.Find(L"afacebook"));
    BOOST_CHECK(trie.Find(L"aface"));
    BOOST_CHECK(trie.Find(L"afacetap"));
    BOOST_CHECK(trie.Find(L"afalcon"));

    BOOST_CHECK(!trie.Find(L"fachion"));
    BOOST_CHECK(!trie.Find(L"fase"));
    BOOST_CHECK(!trie.Find(L"facetab"));


    BOOST_CHECK(!trie.Find(L"fa"));
    BOOST_CHECK(trie.Insert(L"fa"));
    BOOST_CHECK(trie.Find(L"fa"));
}

BOOST_AUTO_TEST_SUITE_END()