#ifndef CARD_LOADER_H
#define CARD_LOADER_H

#include <optional>
#include <vector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QTreeWidget>
#include "card.h"
// #include <QTreeWidget>

// class QPushButton;

namespace BoosterApp {

    class CardLoader
    {
        public:
            explicit CardLoader();
            void write();
            void write_something();
            std::vector<Card> load_cards();

            // Todo private
            std::optional<std::vector<QString>> load_card_data_files();
        private:
            std::unique_ptr<QXmlStreamReader> p_xml_reader; 
            std::unique_ptr<QXmlStreamWriter> p_xml_writer; 
            std::unique_ptr<std::vector<Card>> p_cards;
            QTreeWidget* p_treeWidget;
            //int m_counter = 0;
            //QTreeWidget tree_widget; 
    };

} // namespace

#endif // CARD_LOADER_H
