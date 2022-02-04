#pragma once

#include <ls3p/messages/common.hpp>
#include <ls3p/messages/caps/TextDocumentClientCapabilities.hpp>

namespace ls3p::messages
{

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

}