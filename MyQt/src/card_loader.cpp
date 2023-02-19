#include <QIODevice>
#include <QTreeWidgetItem>
#include <QString>
#include <QObject>
#include <QStringView>
#include <QTextStream>
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
        p_cards->reserve(50000);
        // p_treeWidget = new QTreeWidget();  
        // QStringList labels; 
        // labels << QObject::tr("jooo-o") << QObject::tr("eikojuu");
        // p_treeWidget->setHeaderLabels(labels);
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

    void CardLoader::load_cards()
    {
        auto lists = load_card_data_files();

        if (lists.has_value()) {
           for (const auto& list : *lists) {
               // std::cout << list.toStdString() << std::endl;
               QFile file(QString("lackey/").append(list)); // TODO: remove lackey.
               if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                   std::cout << "Unable to open file " << list.toStdString() << std::endl;
                   return;
               }

               QTextStream ts(&file);

               QString line;

               uint counter = 0;
               while (ts.readLineInto(&line)) {
                   if (counter == 0) { counter++; continue; }
                   Card c;
                   bool succeed = c.parse(line.toStdString());
                   if (succeed) {
                       // p_cards->push_back(c);

                       auto it = p_set_cards.insert(
                               std::pair<std::string, std::vector<Card>>(c.get_set(), std::vector<Card>()));  
                       (*it.first)
                           .second
                           .push_back(c);
                   }
               }
               //s.append(ts.readAll());
           }
        }
        // int lkm = 0;
        // auto the_it = p_set_cards.begin(); 
        // while (the_it != p_set_cards.end())
        // {
        //     int joo_o = 0;
        //     for (const auto& card : the_it->second) {
        //         std::cout << joo_o << " -> " << card.get_set() << " :: " << card.get_name() << std::endl;
        //         joo_o++;
        //     }
        //     the_it++;

        // }
        //std::cout << "Number of cards parsed ==  " << p_cards->size() << std::endl;
    }

    std::optional<std::vector<QString>> CardLoader::load_card_data_files()
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

            if (p_xml_reader->isWhitespace()) { }

            else if (elem_type == QXmlStreamReader::StartElement) {

               auto the_name = (p_xml_reader->name().toString());

               p_xml_reader->readNext(); 

               while (!p_xml_reader->isEndElement()) {
                   if (p_xml_reader->isWhitespace()) { p_xml_reader->readNext(); continue; } 
                   else if (p_xml_reader->isCharacters()) {
                       (*set_file_names).push_back(p_xml_reader->text().toString());
                   }
                   p_xml_reader->readNext();
               }
            }
            elem_type = p_xml_reader->readNext(); 
        }

        if (p_xml_reader->hasError()) {
            std::cout << "An error occured while parsing ListOfCardDataFiles.txt" << std::endl;
            return {};
        }
        
        return set_file_names;

    }
} // namespace
