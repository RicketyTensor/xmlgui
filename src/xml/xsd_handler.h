#pragma once
#include <filesystem>
#include "../node.h"
#include <vector>
#include <libxml/parser.h>
#include <libxml/tree.h>

namespace xmlgui {
    class XSDHandler {
        public:
        XSDHandler(const std::filesystem::path& file);
        ~XSDHandler();

        const xmlNode* get_type(const xmlNode* parent) const;

        private:
        xmlDoc *xml_doc = NULL;
        xmlNode *xml_root = NULL;
    };
}
