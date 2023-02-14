#ifndef CARD_LOADER_H
#define CARD_LOADER_H

#include <optional>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
// #include <QTreeWidget>

class QPushButton;

namespace BoosterApp {

    class CardLoader
    {
        public:
            explicit CardLoader();
            void write();
            void write_something();
        private:
            std::unique_ptr<QXmlStreamReader> p_xml_reader; 
            std::unique_ptr<QXmlStreamWriter> p_xml_writer; 
            //int m_counter = 0;
            //QTreeWidget tree_widget; 
    };

} // namespace

#endif // CARD_LOADER_H