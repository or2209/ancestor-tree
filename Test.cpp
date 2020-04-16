#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace family;


TEST_CASE("Test throw error")
{
        family::Tree T4("ariel");
        T4.addFather("ariel", "netanel");
        T4.addMother("ariel", "lilach");
        T4.addFather("netanel", "hanoka");
        T4.addMother("netanel", "malka");
        T4.addFather("lilach", "menashe");
        T4.addMother("lilach", "shoshana");
        //relation
        CHECK(T4.relation("malka") == string("grandmother"));
        CHECK(T4.relation("ariel") == string("me"));
        //add another father and mother or add to unrelated son a father and mother
        // T4.addFather("ariel", "dan");
        // T4.addMother("ariel", "dana");
        // T4.addFather("aaaa", "netanel");
        // T4.addMother("aaaa", "lilach");
        CHECK_THROWS(T4.remove("ariel"));
        CHECK_THROWS(T4.remove("or"));
        CHECK_THROWS(T4.addFather("ariel","yoav"));
        CHECK_THROWS(T4.addMother("lilach","ariel"));
        CHECK_THROWS(T4.addFather("ariel", "dan"));
        CHECK_THROWS(T4.addMother("ariel", "dana"));
        CHECK_THROWS(T4.addFather("aaaa", "netanel"));
        CHECK_THROWS(T4.addMother("aaaa", "lilach"));
}

TEST_CASE("test all functions in yosef tree")
{
    family::Tree T("Yosef");          // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov")    // Tells the tree that the father of Yosef is Yaakov.
        .addMother("Yosef", "Rachel") // Tells the tree that the mother of Yosef is Rachel.
        .addFather("Yaakov", "Isaac")
        .addMother("Yaakov", "Rivka")
        .addFather("Isaac", "Avraham")
        .addFather("Avraham", "Terah");
    //test relation functions
    CHECK(T.relation("Yaakov") == string("father"));
    CHECK(T.relation("Rachel") == string("mother"));
    CHECK(T.relation("Rivka") == string("grandmother"));
    CHECK(T.relation("Avraham") == string("great-grandfather"));
    CHECK(T.relation("Terah") == string("great-great-grandfather"));
    CHECK(T.relation("xyz") == string("unrelated"));
    CHECK(T.relation("Yosef") == string("me"));
    //test find function
    CHECK(T.find("mother") == string("Rachel"));
    CHECK(T.find("father") == string("Yaakov"));
    CHECK(T.find("grandmother") == string("Rivka"));
    CHECK(T.find("grandfather") == string("Isaac"));
    CHECK(T.find("me") == string("Yosef"));
    CHECK(T.find("great-grandfather") == string("Avraham"));
    //realation after remove node from the tree
    T.remove("Isaac");
    CHECK(T.relation("Avraham") == string("unrelated"));
    CHECK(T.relation("Terah") == string("unrelated"));
    CHECK(T.relation("Yaakov") == string("father"));
    T.addFather("Yaakov", "Isaac");
    CHECK(T.relation("Isaac") == string("grandfather"));
    //remove the root in the Tree
    // CHECK_THROWS(T2.remove("Yosef"));
    // T.deleteTree(T);
}

TEST_CASE("Test function in or tree")
{
    family::Tree T2("or");
    T2.addFather("or", "aharon");
    T2.addMother("or", "lea");
    T2.addFather("aharon", "michael");
    T2.addMother("aharon", "miriam");
    T2.addFather("michael", "kaduri");
    T2.addMother("michael", "roza");
    T2.addFather("kaduri", "ribo");
    //test relation functions
    CHECK(T2.relation("aharon") == string("father"));
    CHECK(T2.relation("lea") == string("mother"));
    CHECK(T2.relation("miriam") == string("grandmother"));
    CHECK(T2.relation("kaduri") == string("great-grandfather"));
    CHECK(T2.relation("ribo") == string("great-great-grandfather"));
    CHECK(T2.relation("xyz") == string("unrelated"));
    CHECK(T2.relation("or") == string("me"));
    CHECK(T2.relation("michael") == string("grandfather"));
    CHECK(T2.relation("roza") == string("great-grandmother"));
    //test find function
    CHECK(T2.find("mother") == string("lea"));
    CHECK(T2.find("father") == string("aharon"));
    CHECK(T2.find("grandmother") == string("miriam"));
    CHECK(T2.find("grandfather") == string("michael"));
    CHECK(T2.find("me") == string("or"));
    // CHECK(T2.find("great-grandmother") == string("michael"));
    // CHECK(T2.find("great-grandfather")==string("kaduri"));
    // CHECK(T2.find("great-great-grandfather")==string("ribo"));
    //realation after remove node from the tree
    T2.remove("michael");
    CHECK(T2.relation("roza") == string("unrelated"));
    CHECK(T2.relation("kaduri") == string("unrelated"));
    CHECK(T2.relation("ribo") == string("unrelated"));
    CHECK(T2.relation("michael") == string("unrelated"));
    T2.addFather("aharon", "michael");
    T2.addMother("michael", "roza");
    T2.addFather("michael", "kaduri");
    T2.addFather("kaduri", "ribo");
    CHECK(T2.relation("michael") == string("grandfather"));
    CHECK(T2.relation("roza") == string("great-grandmother"));
    CHECK(T2.relation("kaduri") == string("great-grandfather"));
    CHECK(T2.relation("ribo") == string("great-great-grandfather"));
}

TEST_CASE("Test function in abc tree")
{
    family::Tree T3("a");
    T3.addFather("a", "b");
    T3.addMother("a", "c");
    T3.addFather("c", "d");
    T3.addMother("c", "e");
    T3.addFather("e", "f");
    T3.addMother("e", "g");
    T3.addFather("g", "h");
    //test relation functions
    CHECK(T3.relation("b") == string("father"));
    CHECK(T3.relation("c") == string("mother"));
    CHECK(T3.relation("e") == string("grandmother"));
    CHECK(T3.relation("f") == string("great-grandfather"));
    CHECK(T3.relation("h") == string("great-great-grandfather"));
    CHECK(T3.relation("xyz") == string("unrelated"));
    CHECK(T3.relation("a") == string("me"));
    CHECK(T3.relation("d") == string("grandfather"));
    CHECK(T3.relation("g") == string("great-grandmother"));
    //test find function
    CHECK(T3.find("mother") == string("c"));
    CHECK(T3.find("father") == string("b"));
    // CHECK(T3.find("grandmother")==string("e"));
    CHECK(T3.find("grandfather") == string("d"));
    CHECK(T3.find("me") == string("a"));
    // CHECK(T3.find("great-grandfather")==string("kaduri"));
    // CHECK(T3.find("great-great-grandfather")==string("ribo"));
    //realation after remove node from the tree
    T3.remove("e");
    CHECK(T3.relation("e") == string("unrelated"));
    CHECK(T3.relation("f") == string("unrelated"));
    CHECK(T3.relation("g") == string("unrelated"));
    CHECK(T3.relation("h") == string("unrelated"));
    T3.addMother("c", "e");
    T3.addMother("e", "g");
    T3.addFather("e", "f");
    T3.addFather("g", "h");
    CHECK(T3.relation("d") == string("grandfather"));
    CHECK(T3.relation("g") == string("great-grandmother"));
    CHECK(T3.relation("f") == string("great-grandfather"));
    CHECK(T3.relation("h") == string("great-great-grandfather"));
}

TEST_CASE("Test function in uri tree")
{
    family::Tree T4("uri");
    T4.addFather("uri", "uzi");
    T4.addMother("uri", "keren");
    T4.addFather("keren", "shimon");
    T4.addMother("keren", "aviva");
    T4.addFather("shimon", "ari");
    T4.addMother("shimon", "meri");
    T4.addFather("meri", "miri");
    //test relation functions
    CHECK(T4.relation("uzi") == string("father"));
    CHECK(T4.relation("keren") == string("mother"));
    CHECK(T4.relation("aviva") == string("grandmother"));
    CHECK(T4.relation("ari") == string("great-grandfather"));
    CHECK(T4.relation("miri") == string("great-great-grandfather"));
    CHECK(T4.relation("xyz") == string("unrelated"));
    CHECK(T4.relation("uri") == string("me"));
    CHECK(T4.relation("shimon") == string("grandfather"));
    CHECK(T4.relation("meri") == string("great-grandmother"));
    //test find function
    CHECK(T4.find("mother") == string("keren"));
    CHECK(T4.find("father") == string("uzi"));
    // CHECK(T3.find("grandmother")==string("e"));
    CHECK(T4.find("grandfather") == string("shimon"));
    CHECK(T4.find("me") == string("uri"));
    // CHECK(T4.find("great-grandfather")==string("kaduri"));
    // CHECK(T4.find("great-great-grandfather")==string("ribo"));
    //realation after remove node from the tree
    T4.remove("shimon");
    CHECK(T4.relation("shimon") == string("unrelated"));
    CHECK(T4.relation("ari") == string("unrelated"));
    CHECK(T4.relation("meri") == string("unrelated"));
    CHECK(T4.relation("miri") == string("unrelated"));
    CHECK(T4.relation("miri") == string("unrelated"));
    CHECK(T4.relation("lol") == string("unrelated"));
    CHECK(T4.relation("root") == string("unrelated"));

    T4.addFather("keren", "shimon");
    T4.addMother("shimon", "meri");
    T4.addFather("shimon", "ari");
    T4.addFather("meri", "miri");
    //  CHECK( T3.relation("shimon") ==string("grandfather"));
    //  CHECK( T3.relation("meri") ==string("great-grandmother"));
    //  CHECK( T3.relation("ari") ==string("great-grandfather"));
    //  CHECK( T3.relation("miri") ==string("great-great-grandfather"));
}


TEST_CASE("Test function in abc tree")
{
    family::Tree T5("koko");
    T5.addFather("koko", "shoko");
    T5.addMother("koko", "moko");
    T5.addFather("shoko", "tv");
    T5.addMother("shoko", "tz");
    T5.addFather("tv", "r");
    T5.addMother("tv", "l");
    T5.addFather("l", "z");
    //test relation functions
    CHECK(T5.relation("shoko") == string("father"));
    CHECK(T5.relation("moko") == string("mother"));
    CHECK(T5.relation("tz") == string("grandmother"));
    CHECK(T5.relation("r") == string("great-grandfather"));
    CHECK(T5.relation("z") == string("great-great-grandfather"));
    CHECK(T5.relation("xyz") == string("unrelated"));
    CHECK(T5.relation("koko") == string("me"));
    CHECK(T5.relation("tv") == string("grandfather"));
    CHECK(T5.relation("l") == string("great-grandmother"));
    //test find function
    CHECK(T5.find("mother") == string("moko"));
    CHECK(T5.find("father") == string("shoko"));
    // CHECK(T3.find("grandmother")==string("e"));
    CHECK(T5.find("grandfather") == string("tv"));
    CHECK(T5.find("me") == string("koko"));
    // CHECK(T2.find("great-grandfather")==string("kaduri"));
    // CHECK(T2.find("great-great-grandfather")==string("ribo"));
    //realation after remove node from the tree
    T5.remove("tv");
    CHECK(T5.relation("tv") == string("unrelated"));
    CHECK(T5.relation("r") == string("unrelated"));
    CHECK(T5.relation("l") == string("unrelated"));
    CHECK(T5.relation("z") == string("unrelated"));
    T5.addFather("shoko", "tv");
    T5.addMother("tv", "l");
    T5.addFather("tv", "r");
    T5.addFather("l", "z");
    CHECK(T5.relation("tv") == string("grandfather"));
    CHECK(T5.relation("l") == string("great-grandmother"));
    CHECK(T5.relation("r") == string("great-grandfather"));
    CHECK(T5.relation("z") == string("great-great-grandfather"));
}

