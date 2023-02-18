#include <QIODevice>
#include <QTreeWidgetItem>
#include <QString>
#include <QObject>
#include <QStringView>
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
        p_treeWidget = new QTreeWidget();  
        QStringList labels; 
        labels << QObject::tr("jooo-o") << QObject::tr("eikojuu");
        p_treeWidget->setHeaderLabels(labels);
    }

    void CardLoader::write() {}

    void CardLoader::write_something()
    {
        QFile file("eki.txt");
        Card c;

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;

        p_xml_writer->setDevice(&file);
        p_xml_writer->setAutoFormatting(true);
        c.write(p_xml_writer.get());
        p_xml_writer->writeStartDocument();
        p_xml_writer->writeStartElement("bookmark");
        // p_xml_writer->writeAttribute("href", "http://qt-project.org/");
        // p_xml_writer->writeTextElement("title", "Qt Project");
        // p_xml_writer->writeEndElement(); // bookmark
        // p_xml_writer->writeEndDocument();
    }

    std::optional<std::vector<QString>> CardLoader::load_set_information()
    {
        auto set_file_names = std::make_optional<std::vector<QString>>(); 

        QFile file("lackey/ListOfCardDataFiles.txt");

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            std::cout << "Unable to open ListOfCardDataFiles.txt" << std::endl;
            
        }

        int lkm = 0;
        p_xml_reader->setDevice(&file);

        auto elem_type = p_xml_reader->readNext(); 

        while (!p_xml_reader->atEnd()) {

            // Skip whitespaces.
            if (p_xml_reader->isWhitespace()) { 
               // std::cout << "Emphty" << std::endl;
            }
            // Parse.
            else if (elem_type == QXmlStreamReader::StartElement) {

               auto the_name = (p_xml_reader->name().toString());
               std::cout << "<" << the_name.toStdString() << ">" << std::endl;

               p_xml_reader->readNext(); 

               while (!p_xml_reader->isEndElement()) {
                   if (p_xml_reader->isWhitespace()) { p_xml_reader->readNext(); continue; } 
                   else if (p_xml_reader->isCharacters()) {
                       (*set_file_names).push_back(p_xml_reader->text().toString());
                       // std::cout << (p_xml_reader->text()).toString().toStdString() << std::endl;
                   }
                   p_xml_reader->readNext();
               }
               std::cout << "<" << the_name.toStdString() << "/>" << std::endl;

               // auto jep = the_name.compare(QString("filetoinclude"));
               // if (jep) {
               //     std::cout << "filestoinclude!!!" << std::endl;
               // }
               // std::cout << (p_xml_reader->name()).toString().toStdString() << std::endl;
               // auto attributes = p_xml_reader->attributes();
            }
            else if (elem_type == QXmlStreamReader::EndElement) {
               std::cout << "End element." << std::endl;
            }

            else if (elem_type == QXmlStreamReader::StartDocument) {
               // std::cout << "Start document." << std::endl;
            }

            else if (elem_type == QXmlStreamReader::EndDocument) {
               // std::cout << "End document." << std::endl;
            }
            else if (elem_type == QXmlStreamReader::Characters) {
               std::cout << "Characters." << std::endl;
               std::cout << (p_xml_reader->text()).toString().toStdString() << std::endl;
            }
            else if (elem_type == QXmlStreamReader::StartDocument) {
               std::cout << "Start document." << std::endl;
            }
            else if (elem_type == QXmlStreamReader::Comment) {
               std::cout << "Comment." << std::endl;
            }
            else if (elem_type == QXmlStreamReader::DTD) {
               std::cout << "DTD." << std::endl;
            }
            else if (elem_type == QXmlStreamReader::EntityReference) {
               std::cout << "EntityReference." << std::endl;
            }
            else if (elem_type == QXmlStreamReader::ProcessingInstruction) {
               std::cout << "ProcessingInstruction." << std::endl;
            }
            //std::cout << elem_type << std::endl;
            elem_type = p_xml_reader->readNext(); 
        }
        
        return set_file_names;

    }
} // namespace
