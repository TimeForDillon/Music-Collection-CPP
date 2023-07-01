#include "music_collection.h"

Tune::Tune()
{
    title = "";
}

Tune::Tune(const string &n)
{
    title = n;
}

const string & Tune::get_title() const
{
    return title;
}

Music_collection::Music_collection()
{
    number = 0;
    max = 100;
    collection = new Tune[max];
}

Music_collection::Music_collection(int n)
{
    number = 0;
    max = n;
    collection = new Tune[max];
}

Music_collection::Music_collection(const Music_collection &m)
{
    number = m.number;
    max = m.max;
    collection = new Tune[m.max];
    for(int i=0;i<number;i++) collection[i] = m.collection[i];
    //copy(m.collection, m.collection+number, collection);
}

Music_collection::~Music_collection()
{
    delete[] collection;
}

bool Music_collection::add_tune(const Tune &t)
{
    if(number > max) return false;
    else
    {
        collection[number] = t;
        number++;
        return true;
    }
}

bool Music_collection::set_tune(int index, const Tune &t)
{
    if(index >= number) return false;
    else
    {
        collection[index] = t;
        return true;
    }
}

Music_collection& Music_collection::operator=(const Music_collection &m)
{
    if(this == &m)
    {
        return *this;
    }

    number = m.number;
    max = m.max;
    for(int i=0;i<number;i++) collection[i] = m.collection[i];

    return *this;
}

ostream & operator<<( ostream &out, const Music_collection &m )
{
    for(int i = 0; i<m.number; i++)
    {
        out << m.collection[i].get_title() << endl;
    }

    return out;
}
