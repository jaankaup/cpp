#include <QIODevice>
#include <QTreeWidgetItem>
#include <QString>
#include "card_loader.h"
#include "card.h"

namespace BoosterApp {

    CardLoader::CardLoader()
    {
        QXmlStreamReader xml;

        // Create xml reader.
        p_xml_reader = std::make_unique<QXmlStreamReader>(); 
        p_xml_writer = std::make_unique<QXmlStreamWriter>(); 
        p_cards = std::make_unique<std::vector<Card>>(); 

    }

    void CardLoader::write() {}

    void CardLoader::write_something()
    {
        QFile file("eki.txt");
        Card c;

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;

        p_xml_writer->setDevice(&file); //(jaahans);
        p_xml_writer->setAutoFormatting(true);
        c.write(p_xml_writer.get());
        // // p_xml_writer->writeStartDocument();
        // p_xml_writer->writeStartElement("bookmark");
        // p_xml_writer->writeAttribute("href", "http://qt-project.org/");
        // p_xml_writer->writeTextElement("title", "Qt Project");
        // p_xml_writer->writeEndElement(); // bookmark
        // p_xml_writer->writeEndDocument();
    }

} // namespace
