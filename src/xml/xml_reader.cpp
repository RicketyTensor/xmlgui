#include "xml_reader.h"
#include <vector>
#include <libxml/parser.h>
#include <libxml/tree.h>

namespace xmlgui {
    namespace {
            void parse_node(xmlNode* parent, std::vector<Node>* nodes, int level) {
                level++;
                xmlNode *cur_node = NULL;

                // Loop over
                for (cur_node = parent; cur_node; cur_node = cur_node->next) {
                    if (cur_node->type == XML_ATTRIBUTE_NODE) {
                    }
                    else if (cur_node->type == XML_ELEMENT_NODE) {
                        nodes->emplace_back(Counter::GetNextId(), (char*)cur_node->name, ImColor(255, 128, 128));
                        parse_node(cur_node->children, nodes, level);
                    }
                }
            }

            Node SpawnInputActionNode()
            {
                Node node(Counter::GetNextId(), "InputAction Fire", ImColor(255, 128, 128));
                node.Outputs.emplace_back(Counter::GetNextId(), "", PinType::Delegate);
                node.Outputs.emplace_back(Counter::GetNextId(), "Pressed", PinType::Flow);
                node.Outputs.emplace_back(Counter::GetNextId(), "Released", PinType::Flow);

                // BuildNode(&node);
                node.assemble();

                return std::move(node);
            }
    }
    std::vector<Node> XMLReader::read_xml(const std::filesystem::path& file) {
        xmlDoc *doc = NULL;
        xmlNode *root = NULL;

        // parse the file and get the DOM 
        if ((doc = xmlReadFile(file.c_str(), NULL, 0)) == NULL){
           printf("error: could not parse file %sn", file.c_str());
           exit(-1);
        }

        root = xmlDocGetRootElement(doc);
        std::vector<Node> nodes;
        parse_node(root, &nodes, 0);

        xmlFreeDoc(doc);       // free document
        xmlCleanupParser();    // Free globals
        return std::move(nodes);
    }
}