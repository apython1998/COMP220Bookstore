//
// Created by benja on 11/27/2017.
//

#include "Title.h"
#include "LinkedQueue.h"

Title::Title() {
    waitlist=new LinkedQueue<Person>();
}

Title::Title(const Title &toCopy){
    name=toCopy.name;
    have=toCopy.have;
    want=toCopy.want;
    waitlist=new LinkedQueue<Person>(); //fixme
    //waitlist=new LinkedQueue<Person>((LinkedQueue)*toCopy.waitlist);
}
