#include <vector>
#include "card.h"
#include "misc.h"

namespace BoosterApp {

    bool Card::parse(const std::string& str)
    {
        // TODO: !!!!!
        // auto vec = Misc::split(str, "/t");
        return true;
    }

    //<card><name id="lea/195">Fungusaur</name><set>alpha</set></card>
    void Card::write(QXmlStreamWriter* writer)
    {
        writer->writeStartElement("card");
        writer->writeStartElement("name");
        // writer->writeStartElement("name");
        //writer->writeTextElement("name", "Fungusaur");
        writer->writeAttribute("id", "lea/195");
        writer->writeAttribute("id", "lea/195");
        writer->writeEndElement(); // bookmark
        writer->writeEndElement(); // bookmark
    }

} //namespace
