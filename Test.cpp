#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
#include <iostream>

using namespace std;
namespace family{

TEST_CASE("test all functions in yosef tree"){
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
            .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah");
    //test relation functions
            CHECK(T.relation("Yaakov")==string("father"));
            CHECK(T.relation("Rachel")==string("mother"));
            CHECK(T.relation("Rivka")==string("grandmother"));
            CHECK(T.relation("Avraham")==string("great-grandfather"));
            CHECK(T.relation("Terah")==string("great-great-grandfather"));
            CHECK(T.relation("xyz")==string("unrelated"));
            CHECK(T.relation("Yosef")==string("me"));
    //test find function
            CHECK(T.find("mother")==string("Rachel"));
            CHECK(T.find("father")==string("Yaakov"));
            CHECK(T.find("grandmother")==string("Rivka"));
            CHECK(T.find("grandfather")==string("Isaac"));
            CHECK(T.find("me")==string("Yosef"));
            CHECK(T.find("great-grandfather")==string("Avraham"));
    //realation after remove node from the tree
    T.remove("Isaac");
            CHECK(T.relation("Avraham")==string("unrelated"));
            CHECK(T.relation("Terah")==string("unrelated"));
            CHECK(T.relation("Yaakov")==string("father"));
    T.addFather("Yaakov", "Isaac");
            CHECK( T.relation("Isaac") ==string("grandfather"));
    //remove the root in the Tree
    // CHECK_THROWS(T2.remove("Yosef"));
    // T.deleteTree(T);
}






TEST_CASE("test all functions in yosef tree"){
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
            .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah");
    //test relation functions
            CHECK(T.relation("Yaakov")==string("father"));
            CHECK(T.relation("Rachel")==string("mother"));
            CHECK(T.relation("Rivka")==string("grandmother"));
            CHECK(T.relation("Avraham")==string("great-grandfather"));
            CHECK(T.relation("Terah")==string("great-great-grandfather"));
            CHECK(T.relation("xyz")==string("unrelated"));
            CHECK(T.relation("Yosef")==string("me"));
    //test find function
            CHECK(T.find("mother")==string("Rachel"));
            CHECK(T.find("father")==string("Yaakov"));
            CHECK(T.find("grandmother")==string("Rivka"));
            CHECK(T.find("grandfather")==string("Isaac"));
            CHECK(T.find("me")==string("Yosef"));
            CHECK(T.find("great-grandfather")==string("Avraham"));
    //realation after remove node from the tree
    T.remove("Isaac");
            CHECK(T.relation("Avraham")==string("unrelated"));
            CHECK(T.relation("Terah")==string("unrelated"));
            CHECK(T.relation("Yaakov")==string("father"));
    T.addFather("Yaakov", "Isaac");
}

TEST_CASE("test all functions in yosef tree"){
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
            .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah");
    //test relation functions
            CHECK(T.relation("Yaakov")==string("father"));
            CHECK(T.relation("Rachel")==string("mother"));
            CHECK(T.relation("Rivka")==string("grandmother"));
            CHECK(T.relation("Avraham")==string("great-grandfather"));
            CHECK(T.relation("Terah")==string("great-great-grandfather"));
            CHECK(T.relation("xyz")==string("unrelated"));
            CHECK(T.relation("Yosef")==string("me"));
    //test find function
            CHECK(T.find("mother")==string("Rachel"));
            CHECK(T.find("father")==string("Yaakov"));
            CHECK(T.find("grandmother")==string("Rivka"));
            CHECK(T.find("grandfather")==string("Isaac"));
            CHECK(T.find("me")==string("Yosef"));
            CHECK(T.find("great-grandfather")==string("Avraham"));
    //realation after remove node from the tree
    T.remove("Isaac");
            CHECK(T.relation("Avraham")==string("unrelated"));
            CHECK(T.relation("Terah")==string("unrelated"));
            CHECK(T.relation("Yaakov")==string("father"));
    T.addFather("Yaakov", "Isaac");
}
    TEST_CASE("test all functions in yosef tree"){
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
            .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah");
    //test relation functions
            CHECK(T.relation("Yaakov")==string("father"));
            CHECK(T.relation("Rachel")==string("mother"));
            CHECK(T.relation("Rivka")==string("grandmother"));
            CHECK(T.relation("Avraham")==string("great-grandfather"));
            CHECK(T.relation("Terah")==string("great-great-grandfather"));
            CHECK(T.relation("xyz")==string("unrelated"));
            CHECK(T.relation("Yosef")==string("me"));
    //test find function
            CHECK(T.find("mother")==string("Rachel"));
            CHECK(T.find("father")==string("Yaakov"));
            CHECK(T.find("grandmother")==string("Rivka"));
            CHECK(T.find("grandfather")==string("Isaac"));
            CHECK(T.find("me")==string("Yosef"));
            CHECK(T.find("great-grandfather")==string("Avraham"));
    //realation after remove node from the tree
    T.remove("Isaac");
            CHECK(T.relation("Avraham")==string("unrelated"));
            CHECK(T.relation("Terah")==string("unrelated"));
            CHECK(T.relation("Yaakov")==string("father"));
    T.addFather("Yaakov", "Isaac");
    }
    TEST_CASE("test all functions in yosef tree"){
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
            .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah");
    //test relation functions
            CHECK(T.relation("Yaakov")==string("father"));
            CHECK(T.relation("Rachel")==string("mother"));
            CHECK(T.relation("Rivka")==string("grandmother"));
            CHECK(T.relation("Avraham")==string("great-grandfather"));
            CHECK(T.relation("Terah")==string("great-great-grandfather"));
            CHECK(T.relation("xyz")==string("unrelated"));
            CHECK(T.relation("Yosef")==string("me"));
    //test find function
            CHECK(T.find("mother")==string("Rachel"));
            CHECK(T.find("father")==string("Yaakov"));
            CHECK(T.find("grandmother")==string("Rivka"));
            CHECK(T.find("grandfather")==string("Isaac"));
            CHECK(T.find("me")==string("Yosef"));
            CHECK(T.find("great-grandfather")==string("Avraham"));
    //realation after remove node from the tree
    T.remove("Isaac");
            CHECK(T.relation("Avraham")==string("unrelated"));
            CHECK(T.relation("Terah")==string("unrelated"));
            CHECK(T.relation("Yaakov")==string("father"));
    T.addFather("Yaakov", "Isaac");
    }
    TEST_CASE("test all functions in yosef tree"){
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
            .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah");
    //test relation functions
            CHECK(T.relation("Yaakov")==string("father"));
            CHECK(T.relation("Rachel")==string("mother"));
            CHECK(T.relation("Rivka")==string("grandmother"));
            CHECK(T.relation("Avraham")==string("great-grandfather"));
            CHECK(T.relation("Terah")==string("great-great-grandfather"));
            CHECK(T.relation("xyz")==string("unrelated"));
            CHECK(T.relation("Yosef")==string("me"));
    //test find function
            CHECK(T.find("mother")==string("Rachel"));
            CHECK(T.find("father")==string("Yaakov"));
            CHECK(T.find("grandmother")==string("Rivka"));
            CHECK(T.find("grandfather")==string("Isaac"));
            CHECK(T.find("me")==string("Yosef"));
            CHECK(T.find("great-grandfather")==string("Avraham"));
    //realation after remove node from the tree
    T.remove("Isaac");
            CHECK(T.relation("Avraham")==string("unrelated"));
            CHECK(T.relation("Terah")==string("unrelated"));
            CHECK(T.relation("Yaakov")==string("father"));
    T.addFather("Yaakov", "Isaac");
    }
    TEST_CASE("test all functions in yosef tree"){
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
            .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah");
    //test relation functions
            CHECK(T.relation("Yaakov")==string("father"));
            CHECK(T.relation("Rachel")==string("mother"));
            CHECK(T.relation("Rivka")==string("grandmother"));
            CHECK(T.relation("Avraham")==string("great-grandfather"));
            CHECK(T.relation("Terah")==string("great-great-grandfather"));
            CHECK(T.relation("xyz")==string("unrelated"));
            CHECK(T.relation("Yosef")==string("me"));
    //test find function
            CHECK(T.find("mother")==string("Rachel"));
            CHECK(T.find("father")==string("Yaakov"));
            CHECK(T.find("grandmother")==string("Rivka"));
            CHECK(T.find("grandfather")==string("Isaac"));
            CHECK(T.find("me")==string("Yosef"));
            CHECK(T.find("great-grandfather")==string("Avraham"));
    //realation after remove node from the tree
    T.remove("Isaac");
            CHECK(T.relation("Avraham")==string("unrelated"));
            CHECK(T.relation("Terah")==string("unrelated"));
            CHECK(T.relation("Yaakov")==string("father"));
    T.addFather("Yaakov", "Isaac");
    }
    TEST_CASE("test all functions in yosef tree"){
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
            .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah");
    //test relation functions
            CHECK(T.relation("Yaakov")==string("father"));
            CHECK(T.relation("Rachel")==string("mother"));
            CHECK(T.relation("Rivka")==string("grandmother"));
            CHECK(T.relation("Avraham")==string("great-grandfather"));
            CHECK(T.relation("Terah")==string("great-great-grandfather"));
            CHECK(T.relation("xyz")==string("unrelated"));
            CHECK(T.relation("Yosef")==string("me"));
    //test find function
            CHECK(T.find("mother")==string("Rachel"));
            CHECK(T.find("father")==string("Yaakov"));
            CHECK(T.find("grandmother")==string("Rivka"));
            CHECK(T.find("grandfather")==string("Isaac"));
            CHECK(T.find("me")==string("Yosef"));
            CHECK(T.find("great-grandfather")==string("Avraham"));
    //realation after remove node from the tree
    T.remove("Isaac");
            CHECK(T.relation("Avraham")==string("unrelated"));
            CHECK(T.relation("Terah")==string("unrelated"));
            CHECK(T.relation("Yaakov")==string("father"));
    T.addFather("Yaakov", "Isaac");
    }
    TEST_CASE("test all functions in yosef tree"){
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
            .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah");
    //test relation functions
            CHECK(T.relation("Yaakov")==string("father"));
            CHECK(T.relation("Rachel")==string("mother"));
            CHECK(T.relation("Rivka")==string("grandmother"));
            CHECK(T.relation("Avraham")==string("great-grandfather"));
            CHECK(T.relation("Terah")==string("great-great-grandfather"));
            CHECK(T.relation("xyz")==string("unrelated"));
            CHECK(T.relation("Yosef")==string("me"));
    //test find function
            CHECK(T.find("mother")==string("Rachel"));
            CHECK(T.find("father")==string("Yaakov"));
            CHECK(T.find("grandmother")==string("Rivka"));
            CHECK(T.find("grandfather")==string("Isaac"));
            CHECK(T.find("me")==string("Yosef"));
            CHECK(T.find("great-grandfather")==string("Avraham"));
    //realation after remove node from the tree
    T.remove("Isaac");
            CHECK(T.relation("Avraham")==string("unrelated"));
            CHECK(T.relation("Terah")==string("unrelated"));
            CHECK(T.relation("Yaakov")==string("father"));
    T.addFather("Yaakov", "Isaac");
    }
    TEST_CASE("test all functions in yosef tree"){
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
            .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah");
    //test relation functions
            CHECK(T.relation("Yaakov")==string("father"));
            CHECK(T.relation("Rachel")==string("mother"));
            CHECK(T.relation("Rivka")==string("grandmother"));
            CHECK(T.relation("Avraham")==string("great-grandfather"));
            CHECK(T.relation("Terah")==string("great-great-grandfather"));
            CHECK(T.relation("xyz")==string("unrelated"));
            CHECK(T.relation("Yosef")==string("me"));
    //test find function
            CHECK(T.find("mother")==string("Rachel"));
            CHECK(T.find("father")==string("Yaakov"));
            CHECK(T.find("grandmother")==string("Rivka"));
            CHECK(T.find("grandfather")==string("Isaac"));
            CHECK(T.find("me")==string("Yosef"));
            CHECK(T.find("great-grandfather")==string("Avraham"));
    //realation after remove node from the tree
    T.remove("Isaac");
            CHECK(T.relation("Avraham")==string("unrelated"));
            CHECK(T.relation("Terah")==string("unrelated"));
            CHECK(T.relation("Yaakov")==string("father"));
    T.addFather("Yaakov", "Isaac");
    }
    TEST_CASE("test all functions in yosef tree"){
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
    T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
            .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
            .addFather("Yaakov", "Isaac")
            .addMother("Yaakov", "Rivka")
            .addFather("Isaac", "Avraham")
            .addFather("Avraham", "Terah");
    //test relation functions
            CHECK(T.relation("Yaakov")==string("father"));
            CHECK(T.relation("Rachel")==string("mother"));
            CHECK(T.relation("Rivka")==string("grandmother"));
            CHECK(T.relation("Avraham")==string("great-grandfather"));
            CHECK(T.relation("Terah")==string("great-great-grandfather"));
            CHECK(T.relation("xyz")==string("unrelated"));
            CHECK(T.relation("Yosef")==string("me"));
    //test find function
            CHECK(T.find("mother")==string("Rachel"));
            CHECK(T.find("father")==string("Yaakov"));
            CHECK(T.find("grandmother")==string("Rivka"));
            CHECK(T.find("grandfather")==string("Isaac"));
            CHECK(T.find("me")==string("Yosef"));
            CHECK(T.find("great-grandfather")==string("Avraham"));
    //realation after remove node from the tree
    T.remove("Isaac");
            CHECK(T.relation("Avraham")==string("unrelated"));
            CHECK(T.relation("Terah")==string("unrelated"));
            CHECK(T.relation("Yaakov")==string("father"));
    T.addFather("Yaakov", "Isaac");
    }
//TEST_CASE("Test functions-or tree") {
//    family::Tree T2 ("or");
//    T2.addFather("or", "aharon")
//            .addMother("or", "lea")
//            .addFather("aharon", "michael")
//            .addMother("aharon", "miriam")
//            .addMother("michael", "roza")
//            .addFather("michael", "kaduri")
//            .addFather("kaduri", "ribo");
//    //test realation function
//            CHECK( T2.relation("aharon") ==string("father"));
//            CHECK( T2.relation("lea") ==string("mother"));
//            CHECK( T2.relation("michael") ==string("grandfather"));
//            CHECK( T2.relation("miriam") ==string("grandmother"));
//            CHECK( T2.relation("kaduri") ==string("great-grandfather"));
//            CHECK( T2.relation("roza") ==string("great-grandmother"));
//            CHECK( T2.relation("ribo") ==string("great-great-grandfather"));
//            CHECK(T2.relation("or")==string("me"));
//    //test find function
//            CHECK(T2.find("mother")==string("lea"));
//            CHECK(T2.find("father")==string("aharon"));
//            CHECK(T2.find("grandmother")==string("miriam"));
//            CHECK(T2.find("grandfather")==string("michael"));
//            CHECK(T2.find("me")==string("or"));
//            CHECK(T2.find("great-grandmother")==string("roza"));
//            CHECK(T2.find("great-grandfather")==string("kaduri"));
//            CHECK(T2.find("great-great-grandfather")==string("ribo"));
//
//    T2.remove("ribo");
//            CHECK( T2.relation("ribo") ==string("unrelated"));
////remove the root in the Tree
//    // CHECK_THROWS(T2.remove("or"));
//    try {
//        cout << T2.find("uncle") << endl;  // throws an exception
//    } catch (const exception& ex) {
//        cout << ex.what() << endl;  // prints "The tree cannot handle the 'uncle' relation"
//    }
//
//
//    //edge cases
//    T2.remove("aharon");
//    try{
//        T2.addFather("aharon", "miriam");
//    }
//    catch(exception &ex){
//        cout<<ex.what()<<endl;
//                CHECK_THROWS(T2.addMother("Isaac", "Sara"));
//
//    }
//    try{
//        T2.addMother("sabina", "sabiha");
//    }
//    catch(exception &ex){
//        cout<<ex.what()<<endl;
//                CHECK_THROWS(T2.addMother("Rami", "Malka"));
//
//    }
//    try{
//        T2.addFather("ribo", "koko");
//    }
//    catch(exception &ex){
//        cout<<ex.what()<<endl;
//                CHECK_THROWS(T2.addFather("Yosi", "Yaki"));
//
//    }
//    try{
//        T2.find("yasmin");
//    }
//    catch(exception &ex){
//        cout<<ex.what()<<endl;
//                CHECK_THROWS(T2.find("brother"));
//    }
//    try{
//        T2.find("great-grandfather");
//    }
//    catch(exception &ex){
//        cout<<ex.what()<<endl;
//                CHECK_THROWS(T2.find("great- great-grampa"));
//    }
//    // T2.display();
////    T2.deleteTree(T2);
//}


// TEST_CASE("Test functions-uri tree") {
//     family::Tree T3 ("uri");
//     T3.addFather("uri", "uzi")
//             .addMother("uri", "keren")
//             .addFather("uzi", ",michael")
//             .addMother("uzi", "miriam")
//             .addMother("michael", "roza")
//             .addFather("michael", "kaduri")
//             .addFather("kaduri", "ribo");
//     //test realation function
//             CHECK( T3.relation("uzi") ==string("father"));
//             CHECK( T3.relation("keren") ==string("mother"));
//             CHECK( T3.relation("michael") ==string("grandfather"));
//             CHECK( T3.relation("miriam") ==string("grandmother"));
//             CHECK( T3.relation("kaduri") ==string("great-grandfather"));
//             CHECK( T3.relation("roza") ==string("great-grandmother"));
//             CHECK( T3.relation("ribo") ==string("great-great-grandfather"));
//             CHECK(T3.relation("uri")==string("me"));
//     //test find function
//             CHECK(T3.find("mother")==string("keren"));
//             CHECK(T3.find("father")==string("uzi"));
//             CHECK(T3.find("grandmother")==string("miriam"));
//             CHECK(T3.find("grandfather")==string("michael"));
//             CHECK(T3.find("me")==string(""));
//             CHECK(T3.find("great-grandmother")==string("roza"));
//             CHECK(T3.find("great-grandfather")==string("kaduri"));
//             CHECK(T3.find("great-great-grandfather")==string("ribo"));

//     T3.remove("ribo");
//             CHECK( T3.relation("ribo") ==string("unrelated"));

//     try {
//         cout << T3.find("uncle") << endl;  // throws an exception
//     } catch (const exception& ex) {
//         cout << ex.what() << endl;  // prints "The tree cannot handle the 'uncle' relation"
//     }

// //remove the root in the Tree
//     // CHECK_THROWS(T2.remove("uri"));
//     //edge cases
//     T3.remove("aharon");
//     try{
//         T3.addFather("aharon", "miriam");
//     }
//     catch(exception &ex){
//         cout<<ex.what()<<endl;
//                 CHECK_THROWS(T3.addMother("Isaac", "Sara"));

//     }
//     try{
//         T3.addMother("sabina", "sabiha");
//     }
//     catch(exception &ex){
//         cout<<ex.what()<<endl;
//                 CHECK_THROWS(T3.addMother("Rami", "Malka"));

//     }
//     try{
//         T3.addFather("ribo", "koko");
//     }
//     catch(exception &ex){
//         cout<<ex.what()<<endl;
//                 CHECK_THROWS(T3.addFather("Yosi", "Yaki"));

//     }
//     try{
//         T3.find("yasmin");
//     }
//     catch(exception &ex){
//         cout<<ex.what()<<endl;
//                 CHECK_THROWS(T3.find("brother"));
//     }
//     try{
//         T3.find("great-grandfather");
//     }
//     catch(exception &ex){
//         cout<<ex.what()<<endl;
//                 CHECK_THROWS(T3.find("great- great-grampa"));
//     }
//     // T3.display();
// //    T3.deleteTree(T3);
// }



// TEST_CASE("Test functions-or tree") {
//     family::Tree T2 ("netanel");
//     T2.addFather("netanel", "asher")
//             .addMother("netanel", "dalia")
//             .addFather("asher", "david")
//             .addMother("asher", "zina")
//             .addMother("dalia", "prida")
//             .addFather("dalia", "him")
//             .addFather("prida", "avram")
//             .addMother("prida","shara");
//     //test realation function
//             CHECK( T2.relation("asher") ==string("father"));
//             CHECK( T2.relation("dalia") ==string("mother"));
//             CHECK( T2.relation("david") ==string("grandfather"));
//             CHECK( T2.relation("prida") ==string("grandmother"));
//             CHECK( T2.relation("avram") ==string("great-grandfather"));
//             CHECK( T2.relation("him") ==string("grandfather"));
//     //CHECK( T2.relation("ribo") ==string("great-great-grandfather"));
//             CHECK(T2.relation("netanel")==string("me"));
//     //test find function
//             CHECK(T2.find("mother")==string("dalia"));
//             CHECK(T2.find("father")==string("asher"));
//             CHECK(T2.find("grandmother")==string("zina"));
//             CHECK(T2.find("grandfather")==string("david"));
//             CHECK(T2.find("me")==string("netanel"));
//             CHECK(T2.find("great-grandmother")==string("shara"));
//             CHECK(T2.find("great-grandfather")==string("avram"));
//     //CHECK(T2.find("great-great-grandfather")==string("ribo"));

//remove the root in the Tree
    // CHECK_THROWS(T2.remove("netanel"));
//}
// TEST_CASE("Test functions-A,B.C tree") {
//     family::Tree T3 ("A");
//     T3.addFather("A", "B")
//             .addMother("A", "C")
//             .addFather("C", "D")
//             .addMother("C", "E")
//             .addMother("E", "F")
//             .addFather("E", "G")
//             .addFather("G", "H");
//     //test realation function
//             CHECK( T3.relation("B") ==string("father"));
//             CHECK( T3.relation("C") ==string("mother"));
//             CHECK( T3.relation("D") ==string("grandfather"));
//             CHECK( T3.relation("E") ==string("grandmother"));
//             CHECK( T3.relation("G") ==string("great-grandfather"));
//             CHECK( T3.relation("F") ==string("great-grandmother"));
//             CHECK( T3.relation("H") ==string("great-great-grandfather"));
//             CHECK(T3.relation("A")==string("me"));
//     //test find function
//             CHECK(T3.find("mother")==string("C"));
//             CHECK(T3.find("father")==string("B"));
//             // CHECK(T3.find("grandmother")==string("E"));
//             CHECK(T3.find("grandfather")==string("D"));
//             CHECK(T3.find("me")==string("A"));
//             CHECK(T3.find("great-grandmother")==string("F"));
//             CHECK(T3.find("great-grandfather")==string("G"));
//             CHECK(T3.find("great-great-grandfather")==string("H"));
//     // T3.remove("E");
//     ////exception relation afret remove 'E' in Tree
// //            CHECK_THROWS(T3.relation("E"));
// //            CHECK_THROWS(T3.relation("G"));
// //            CHECK_THROWS(T3.relation("H"));
// //            CHECK_THROWS(T3.relation("F"));
// //    ///exception find after remove 'E' in Tree
// //         //   CHECK_THROWS(T2.find("grandmother");
// //            CHECK_THROWS(T3.find("great-grandfather"));
// //            CHECK_THROWS(T3.find("great-great-grandfather"));
// //            CHECK_THROWS(T3.find("great-grandmother"));
//     //remove the root in the Tree
//     // CHECK_THROWS(T2.remove("A"));
// }


// TEST_CASE("Test functions-or tree") {
//     family::Tree T2 ("or");
//     T2.addFather("or", "aharon")
//             .addMother("or", "lea")
//             .addFather("aharon", "michael")
//             .addMother("aharon", "miriam")
//             .addMother("michael", "roza")
//             .addFather("michael", "kaduri")
//             .addFather("kaduri", "ribo");
//     //test realation function
//             CHECK( T2.relation("aharon") ==string("father"));
//             CHECK( T2.relation("lea") ==string("mother"));
//             CHECK( T2.relation("michael") ==string("grandfather"));
//             CHECK( T2.relation("miriam") ==string("grandmother"));
//             CHECK( T2.relation("kaduri") ==string("great-grandfather"));
//             CHECK( T2.relation("roza") ==string("great-grandmother"));
//             CHECK( T2.relation("ribo") ==string("great-great-grandfather"));
//             CHECK(T2.relation("or")==string("me"));
//     //test find function
//             CHECK(T2.find("mother")==string("lea"));
//             CHECK(T2.find("father")==string("aharon"));
//             CHECK(T2.find("grandmother")==string("miriam"));
//             CHECK(T2.find("grandfather")==string("michael"));
//             CHECK(T2.find("me")==string("or"));
//             CHECK(T2.find("great-grandmother")==string("roza"));
//             CHECK(T2.find("great-grandfather")==string("kaduri"));
//             CHECK(T2.find("great-great-grandfather")==string("ribo"));

// }
// TEST_CASE("Test functions-or tree") {
//     family::Tree T2 ("or");
//     T2.addFather("or", "aharon")
//             .addMother("or", "lea")
//             .addFather("aharon", "michael")
//             .addMother("aharon", "miriam")
//             .addMother("michael", "roza")
//             .addFather("michael", "kaduri")
//             .addFather("kaduri", "ribo");
//     //test realation function
//             CHECK( T2.relation("aharon") ==string("father"));
//             CHECK( T2.relation("lea") ==string("mother"));
//             CHECK( T2.relation("michael") ==string("grandfather"));
//             CHECK( T2.relation("miriam") ==string("grandmother"));
//             CHECK( T2.relation("kaduri") ==string("great-grandfather"));
//             CHECK( T2.relation("roza") ==string("great-grandmother"));
//             CHECK( T2.relation("ribo") ==string("great-great-grandfather"));
//             CHECK(T2.relation("or")==string("me"));
//     //test find function
//             CHECK(T2.find("mother")==string("lea"));
//             CHECK(T2.find("father")==string("aharon"));
//             CHECK(T2.find("grandmother")==string("miriam"));
//             CHECK(T2.find("grandfather")==string("michael"));
//             CHECK(T2.find("me")==string("or"));
//             CHECK(T2.find("great-grandmother")==string("roza"));
//             CHECK(T2.find("great-grandfather")==string("kaduri"));
//             CHECK(T2.find("great-great-grandfather")==string("ribo"));

// }
// TEST_CASE("Test functions-or tree") {
//     family::Tree T2 ("or");
//     T2.addFather("or", "aharon")
//             .addMother("or", "lea")
//             .addFather("aharon", "michael")
//             .addMother("aharon", "miriam")
//             .addMother("michael", "roza")
//             .addFather("michael", "kaduri")
//             .addFather("kaduri", "ribo");
//     //test realation function
//             CHECK( T2.relation("aharon") ==string("father"));
//             CHECK( T2.relation("lea") ==string("mother"));
//             CHECK( T2.relation("michael") ==string("grandfather"));
//             CHECK( T2.relation("miriam") ==string("grandmother"));
//             CHECK( T2.relation("kaduri") ==string("great-grandfather"));
//             CHECK( T2.relation("roza") ==string("great-grandmother"));
//             CHECK( T2.relation("ribo") ==string("great-great-grandfather"));
//             CHECK(T2.relation("or")==string("me"));
//     //test find function
//             CHECK(T2.find("mother")==string("lea"));
//             CHECK(T2.find("father")==string("aharon"));
//             CHECK(T2.find("grandmother")==string("miriam"));
//             CHECK(T2.find("grandfather")==string("michael"));
//             CHECK(T2.find("me")==string("or"));
//             CHECK(T2.find("great-grandmother")==string("roza"));
//             CHECK(T2.find("great-grandfather")==string("kaduri"));
//             CHECK(T2.find("great-great-grandfather")==string("ribo"));

// }
// TEST_CASE("Test functions-or tree") {
//     family::Tree T2 ("or");
//     T2.addFather("or", "aharon")
//             .addMother("or", "lea")
//             .addFather("aharon", "michael")
//             .addMother("aharon", "miriam")
//             .addMother("michael", "roza")
//             .addFather("michael", "kaduri")
//             .addFather("kaduri", "ribo");
//     //test realation function
//             CHECK( T2.relation("aharon") ==string("father"));
//             CHECK( T2.relation("lea") ==string("mother"));
//             CHECK( T2.relation("michael") ==string("grandfather"));
//             CHECK( T2.relation("miriam") ==string("grandmother"));
//             CHECK( T2.relation("kaduri") ==string("great-grandfather"));
//             CHECK( T2.relation("roza") ==string("great-grandmother"));
//             CHECK( T2.relation("ribo") ==string("great-great-grandfather"));
//             CHECK(T2.relation("or")==string("me"));
//     //test find function
//             CHECK(T2.find("mother")==string("lea"));
//             CHECK(T2.find("father")==string("aharon"));
//             CHECK(T2.find("grandmother")==string("miriam"));
//             CHECK(T2.find("grandfather")==string("michael"));
//             CHECK(T2.find("me")==string("or"));
//             CHECK(T2.find("great-grandmother")==string("roza"));
//             CHECK(T2.find("great-grandfather")==string("kaduri"));
//             CHECK(T2.find("great-great-grandfather")==string("ribo"));

// }
// TEST_CASE("Test functions-or tree") {
//     family::Tree T2 ("or");
//     T2.addFather("or", "aharon")
//             .addMother("or", "lea")
//             .addFather("aharon", "michael")
//             .addMother("aharon", "miriam")
//             .addMother("michael", "roza")
//             .addFather("michael", "kaduri")
//             .addFather("kaduri", "ribo");
//     //test realation function
//             CHECK( T2.relation("aharon") ==string("father"));
//             CHECK( T2.relation("lea") ==string("mother"));
//             CHECK( T2.relation("michael") ==string("grandfather"));
//             CHECK( T2.relation("miriam") ==string("grandmother"));
//             CHECK( T2.relation("kaduri") ==string("great-grandfather"));
//             CHECK( T2.relation("roza") ==string("great-grandmother"));
//             CHECK( T2.relation("ribo") ==string("great-great-grandfather"));
//             CHECK(T2.relation("or")==string("me"));
//     //test find function
//             CHECK(T2.find("mother")==string("lea"));
//             CHECK(T2.find("father")==string("aharon"));
//             CHECK(T2.find("grandmother")==string("miriam"));
//             CHECK(T2.find("grandfather")==string("michael"));
//             CHECK(T2.find("me")==string("or"));
//             CHECK(T2.find("great-grandmother")==string("roza"));
//             CHECK(T2.find("great-grandfather")==string("kaduri"));
//             CHECK(T2.find("great-great-grandfather")==string("ribo"));

// }
}