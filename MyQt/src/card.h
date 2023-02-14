#ifndef CARD
#define CARD

#include<iostream>
#include <QXmlStreamWriter>

namespace BoosterApp {

    class Card {

        public:

            explicit Card() {}
            bool parse(const std::string& str);          
            void write(QXmlStreamWriter* device);

        private:

            std::string p_name;
            std::string p_set;
            std::string p_imagefile;
            std::string p_actualset;
            std::string p_color;
            std::string p_colorid;
            std::string p_cost;
            std::string p_manavalue;
            std::string p_type;
            std::string p_power;
            std::string p_toughness;
            std::string p_loyalty;
            std::string p_rarity;
            std::string p_draftqualities;
            std::string p_sound;
            std::string p_script;
            std::string p_text;
    };

} // namespace

#endif // CARD
