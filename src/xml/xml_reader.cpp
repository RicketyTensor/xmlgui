#include "xml_reader.h"
#include "xsd_reader.h"
#include "xsd_handler.h"
#include <vector>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>

namespace xmlgui {
    namespace {
            void parse_node(xmlNode* parent, std::vector<Node>* nodes, int level, 
                            const XSDHandler& schema) {
                level++;
                xmlNode *cur_node = NULL;
                const xmlNode *xsd_node = schema.get_type(parent);

                // Loop over
                for (cur_node = parent; cur_node; cur_node = cur_node->next) {
                    if (cur_node->type == XML_ATTRIBUTE_NODE) {
                        
                    }
                    else if (cur_node->type == XML_ELEMENT_NODE) {
                        nodes->emplace_back(Counter::GetNextId(), (char*)cur_node->name, ImColor(255, 128, 128));
                        parse_node(cur_node->children, nodes, level, schema);
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
    std::vector<Node> XMLReader::read_xml(const std::filesystem::path& xml_file, 
                                          const std::filesystem::path& xsd_file) {
        xmlDoc *xml_doc = NULL;
        xmlNode *xml_root = NULL;

        // parse the schema file
        const XSDHandler schema = XSDReader::read_xsd(xsd_file);

        // parse the file and get the DOM 
        if ((xml_doc = xmlReadFile(xml_file.c_str(), NULL, 0)) == NULL){
           printf("error: could not parse file %sn", xml_file.c_str());
           exit(-1);
        }

        xml_root = xmlDocGetRootElement(xml_doc);
        std::vector<Node> nodes;
        parse_node(xml_root, &nodes, 0, schema);

        xmlFreeDoc(xml_doc);   // free document
        xmlCleanupParser();    // Free globals
        return std::move(nodes);
    }
}