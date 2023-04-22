#pragma once

#include <imgui_node_editor.h>

#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui.h>
#include <imgui_internal.h>

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>


namespace ed = ax::NodeEditor;

using namespace ax;

struct Counter {
    static int m_NextId;

    static int GetNextId() {
        return m_NextId++;
    }
};

enum class PinType
{
    Flow,
    Bool,
    Int,
    Float,
    String,
    Object,
    Function,
    Delegate,
};

enum class PinKind
{
    Output,
    Input
};

enum class NodeType
{
    Blueprint,
    Simple,
    Tree,
    Comment,
    Houdini
};

struct Node;

struct Pin
{
    ed::PinId   ID;
    ::Node*     Node;
    std::string Name;
    PinType     Type;
    PinKind     Kind;

    Pin(int id, const char* name, PinType type):
        ID(id), Node(nullptr), Name(name), Type(type), Kind(PinKind::Input)
    {
    }
};

struct Node
{
    ed::NodeId ID;
    std::string Name;
    std::vector<Pin> Inputs;
    std::vector<Pin> Outputs;
    ImColor Color;
    NodeType Type;
    ImVec2 Size;

    std::string State;
    std::string SavedState;

    Node(int id, const char* name, ImColor color = ImColor(255, 255, 255)):
        ID(id), Name(name), Color(color), Type(NodeType::Blueprint), Size(0, 0)
    {
    }

    void assemble() {
        for (auto& input : this->Inputs)
        {
            input.Node = this;
            input.Kind = PinKind::Input;
        }

        for (auto& output : this->Outputs)
        {
            output.Node = this;
            output.Kind = PinKind::Output;
        }
    }
};

struct Link
{
    ed::LinkId ID;

    ed::PinId StartPinID;
    ed::PinId EndPinID;

    ImColor Color;

    Link(ed::LinkId id, ed::PinId startPinId, ed::PinId endPinId):
        ID(id), StartPinID(startPinId), EndPinID(endPinId), Color(255, 255, 255)
    {
    }
};

// void BuildNode(Node* node)
// {
//     for (auto& input : node->Inputs)
//     {
//         input.Node = node;
//         input.Kind = PinKind::Input;
//     }

//     for (auto& output : node->Outputs)
//     {
//         output.Node = node;
//         output.Kind = PinKind::Output;
//     }
// }
