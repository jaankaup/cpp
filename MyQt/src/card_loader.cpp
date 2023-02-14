#include <QIODevice>
#include <QTreeWidgetItem>
#include "card_loader.h"

#include <QString>

namespace BoosterApp {

    CardLoader::CardLoader()
    {
        QXmlStreamReader xml;

        // Create xml reader.
        p_xml_reader = std::make_unique<QXmlStreamReader>(); 
        p_xml_writer = std::make_unique<QXmlStreamWriter>(); 
    }

    void CardLoader::write() {}
    void CardLoader::write_something()
    {
        QFile file("eki.txt");

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;

        p_xml_writer->setDevice(&file); //(jaahans);
        p_xml_writer->setAutoFormatting(true);
        // p_xml_writer->writeStartDocument();
        p_xml_writer->writeStartElement("bookmark");
        p_xml_writer->writeAttribute("href", "http://qt-project.org/");
        p_xml_writer->writeTextElement("title", "Qt Project");
        p_xml_writer->writeEndElement(); // bookmark
        // p_xml_writer->writeEndDocument();
    }

} // namespace
