#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/caps/ClientCapabilities.hpp>
#include <variant>

namespace ls3p::messages::general
{

struct TextDocumentClientCapabilities
{
    // TODO: synchronization
    // TODO: completion
    // TODO: hover
    // TODO: signatureHelp
    // TODO: declaration
    // TODO: definition
    // TODO: typeDefinition
    // TODO: implementation
    // TODO: references
    // TODO: documentHighlight
    // TODO: documentSymbol
    // TODO: codeAction
    // TODO: codeLens
    // TODO: documentLink
    // TODO: colorProvider
    // TODO: formatting
    // TODO: rangeFormatting
    // TODO: onTypeFormatting
    // TODO: rename
    // TODO: publishDiagnostics
    // TODO: foldingRange
    // TODO: selectionRange
    // TODO: linkedEditingRange
    // TODO: callHierarchy
    // TODO: semanticTokens
    // TODO: moniker
};

struct ClientCapabilities
{
    struct Workspace
    {
        std::optional<bool> apply_edit;

        // TODO: workspaceEdit
        // TODO: didChangeConfiguration
        // TODO: didChangeWatchedFiles
        // TODO: symbol
        // TODO: executeCommand
        // TODO: workspaceFolders
        // TODO: configuration
        // TODO: semanticTokens
        // TODO: codeLens
        // TODO: fileOperations
    };

    std::optional<Workspace> workspace;

    std::optional<TextDocumentClientCapabilities> text_document;

    struct Window
    {
        std::optional<bool> work_done_progress;

        
    };
};

struct InitializeParams
{
    public:
    std::optional<int> process_id;

    struct ClientInfo
    {
        std::string name;
        std::optional<std::string> version;
    };

    std::optional<ClientInfo> client_info;

    std::optional<std::string> locale;

    [[deprecated("root_uri is recommended in the LSP")]]
    std::optional<std::variant<std::string, std::monostate>> root_path;

    std::optional<nlohmann::json> initialization_options;

    ClientCapabilities capabilities;

    // TODO: trace

    std::vector<WorkspaceFolder> workspace_folders;
};

}