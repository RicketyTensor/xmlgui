#include "xsd_handler.h"
#include "../utils/text.hpp"
#include <vector>

namespace xmlgui {
    namespace {
    }

    XSDHandler::XSDHandler(const std::filesystem::path& xml_file) {
        // parse the file and get the DOM 
        if ((xml_doc = xmlReadFile(xml_file.c_str(), NULL, 0)) == NULL){
           printf("error: could not parse file %sn", xml_file.c_str());
           exit(-1);
        }

        xml_root = xmlDocGetRootElement(xml_doc);
    }
    
    XSDHandler::~XSDHandler() {
        xmlFreeDoc(xml_doc);   // free document
        xmlCleanupParser();    // Free globals
    }

    const xmlNode* XSDHandler::get_type(const xmlNode* xml_node) const {
        xmlNode *cur_node = NULL;
        xmlChar* type;

        // Loop over
        for (cur_node = xml_root->children; cur_node; cur_node = cur_node->next) {
            if (cur_node->type == XML_ATTRIBUTE_NODE) {
                
            }
            else if (cur_node->type == XML_ELEMENT_NODE) {
                const auto a = to_string(xmlGetProp(cur_node, (const xmlChar*)"name"));
                const auto b = to_string(xml_node->name);
                if (a == b) {
                    type = xmlGetProp(cur_node, (const xmlChar*)"type");
                    break;
                }
            }
        }

        // Loop over
        for (cur_node = xml_root->children; cur_node; cur_node = cur_node->next) {
            if (cur_node->type == XML_ATTRIBUTE_NODE) {
                
            }
            else if (cur_node->type == XML_ELEMENT_NODE) {
                const std::string a = to_string(xmlGetProp(cur_node, (const xmlChar*)"name"));
                const std::string b = to_string(type);
                const auto wtf = split(b, ":");
                if (a == split(b, ":")[1]) {
                    return cur_node;
                }
            }
        }

        return NULL;
    }
}