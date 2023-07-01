#include "music_collection.h"

int main()
{
    //create a few Tune objects to use later on;
    Music_collection A;
    //add a few tunes to A;
    Tune a("a");
    Tune b("b");
    Tune c("c");
    A.add_tune(a);
    A.add_tune(b);
    A.add_tune(c);
    cout << "Music_collection A" << endl;
    cout << A << endl;
    Music_collection B(A);
    //change a Tune in B using set_tune function;
    Tune d("d");
    B.set_tune(2, d);
    cout << "Music_collection B" << endl;
    cout << B << endl;
    cout << "Music_collection A" << endl;
    cout << A << endl;

    Music_collection C;
    cout << "= operator" << endl;
    C = B;
    //add a Tune to B;
    B.add_tune(a);
    //change a Tune in C using set_tune function;
    C.set_tune(0, d);
    cout << "A: \n" << A << "B:\n" << B << "C: \n" << C << endl;
    // //print A,B,C;
}
