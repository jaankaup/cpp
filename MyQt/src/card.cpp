#include <vector>
#include <string>
#include "card.h"
#include "misc.h"

namespace BoosterApp {

    bool Card::parse(const std::string& str)
    {
        // TODO: !!!!!
        auto maybe_vec = Misc::split_const(str, '\t');
            bool result = false;

        if (maybe_vec.has_value())
        {
            std::cout << "Has value!" << std::endl;

            if ((*maybe_vec).size() != 17) {
                std::cout << "The number of tokens (" << (*maybe_vec).size() << ")." << std::endl;
                result = false;
            }
            else {
                p_name      = (*maybe_vec)[0];
                p_set       = (*maybe_vec)[1];
                p_imagefile = (*maybe_vec)[2];
                p_actualset = (*maybe_vec)[3];
                p_color     = (*maybe_vec)[4];
                p_colorid   = (*maybe_vec)[5];
                p_cost      = (*maybe_vec)[6];
                p_manavalue = (*maybe_vec)[7];
                p_type      = (*maybe_vec)[8];
                p_power     = (*maybe_vec)[9];
                p_toughness = (*maybe_vec)[10];
                p_loyalty   = (*maybe_vec)[11];
                p_rarity    = (*maybe_vec)[12];
                p_draftqualities = (*maybe_vec)[13];
                p_sound     = (*maybe_vec)[14];
                p_script    = (*maybe_vec)[15];
                p_text      = (*maybe_vec)[16];
                result      = true;
            }
            //for (const auto& val : *maybe_vec)
            //{
            //    std::cout << val << std::endl; 
            //}
        }
        else 
        {
            std::cout << "Oh no!" << std::endl;
            result = false;
        }
        return result;
    }

    //<card><name id="lea/195">Fungusaur</name><set>alpha</set></card>
    void Card::write(QXmlStreamWriter* writer)
    {
        QString name = QString::fromStdString(p_name);
        QString id   = QString::fromStdString(p_imagefile);
        QString set  = QString::fromStdString(p_set);

        writer->writeStartElement("card");
        writer->writeStartElement("name");
        writer->writeAttribute("id", id );
        writer->writeCharacters(name);
        writer->writeEndElement();
        writer->writeTextElement("set", set);
        writer->writeEndElement();
        writer->writeEndElement();
    }

} //namespace
