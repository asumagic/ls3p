#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::workspace
{

enum class SymbolKind : UInteger
{
    FILE = 1,
    MODULE = 2,
    NAMESPACE = 3,
    PACKAGE = 4,
    CLASS = 5,
    METHOD = 6,
    PROPERTY = 7,
    FIELD = 8,
    CONSTRUCTOR = 9,
    ENUM = 10,
    INTERFACE = 11,
    FUNCTION = 12,
    VARIABLE = 13,
    CONSTANT = 14,
    STRING = 15,
    NUMBER = 16,
    BOOLEAN = 17,
    ARRAY = 18,
    OBJECT = 19,
    KEY = 20,
    _NULL = 21, // blame C
    ENUM_MEMBER = 22,
    STRUCT = 23,
    EVENT = 24,
    OPERATOR = 25,
    TYPE_PARAMETER = 26
};

enum class SymbolTag : UInteger
{
    DEPRECATED = 1
};

struct WorkspaceSymbolClientCapabilities
{
    std::optional<bool> dynamic_registration;

    struct SymbolKindCaps
    {
        std::optional<std::vector<SymbolKind>> value_set;

        LS3P_ARCHIVE(SymbolKindCaps)
        {
            archive
                ("valueSet", value_set);
        }
    };
    
    std::optional<SymbolKindCaps> symbol_kind;

    struct TagSupport
    {
        std::vector<SymbolTag> value_set;

        LS3P_ARCHIVE(TagSupport)
        {
            archive
                ("valueSet", value_set);
        }
    };

    std::optional<TagSupport> tag_support;

    struct ResolveSupport
    {
        std::vector<std::string> properties;

        LS3P_ARCHIVE(ResolveSupport)
        {
            archive
                ("properties", properties);
        }
    };

    std::optional<ResolveSupport> resolve_support;

    LS3P_ARCHIVE(WorkspaceSymbolClientCapabilities)
    {
        archive
            ("dynamicRegistration", dynamic_registration)
            ("symbolKind", symbol_kind)
            ("tagSupport", tag_support)
            ("resolveSupport", resolve_support);
    }
};

}