#pragma once

#include "ls3p/structs/lang/monikers.hpp"
#include <ls3p/structs/common.hpp>
#include <ls3p/structs/core/markup.hpp>
#include <ls3p/structs/core/regex.hpp>
#include <ls3p/structs/core/trace.hpp>
#include <ls3p/structs/core/workspaceedit.hpp>
#include <ls3p/structs/workspace/configuration.hpp>
#include <ls3p/structs/workspace/folders.hpp>
#include <ls3p/structs/workspace/fswatch.hpp>
#include <ls3p/structs/workspace/symbols.hpp>
#include <ls3p/structs/lang.hpp>

namespace ls3p::structs::general
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
    std::optional<lang::MonikerClientCapabilities> moniker;

    LS3P_ARCHIVE(TextDocumentClientCapabilities)
    {
        archive
            ("moniker", moniker);
    }
};

struct ClientCapabilities
{
    struct Workspace
    {
        std::optional<bool> apply_edit;

        std::optional<core::WorkspaceEditClientCapabilities> workspace_edit;

        std::optional<workspace::DidChangeConfigurationClientCapabilities> did_change_configuration;
        std::optional<workspace::DidChangeWatchedFilesClientCapabilities> did_change_watched_files;
        std::optional<workspace::WorkspaceSymbolClientCapabilities> symbol;
        // TODO: executeCommand
        
        std::optional<bool> workspace_folders;
        std::optional<bool> configuration;

        // TODO: semanticTokens
        // TODO: codeLens

        struct FileOperations
        {
            std::optional<bool> dynamic_registration;

            std::optional<bool> did_create;
            std::optional<bool> will_create;

            std::optional<bool> did_rename;
            std::optional<bool> will_rename;

            std::optional<bool> did_delete;
            std::optional<bool> will_delete;

            LS3P_ARCHIVE(FileOperations)
            {
                archive
                    ("dynamicRegistration", dynamic_registration)
                    ("didCreate", did_create)
                    ("willCreate", will_create)
                    ("didRename", did_rename)
                    ("willRename", will_rename)
                    ("didDelete", did_delete)
                    ("willDelete", will_delete);
            }
        };

        std::optional<FileOperations> file_operations;

        LS3P_ARCHIVE(Workspace)
        {
            archive
                ("applyEdit", apply_edit)
                ("workspaceEdit", workspace_edit)
                ("didChangeConfiguration", did_change_configuration)
                ("didChangeWatchedFiles", did_change_watched_files)
                ("symbol", symbol)
                ("workspaceFolders", workspace_folders)
                ("configuration", configuration)
                ("fileOperations", file_operations);
        }
    };

    std::optional<Workspace> workspace;

    std::optional<TextDocumentClientCapabilities> text_document;

    struct Window
    {
        std::optional<bool> work_done_progress;

        // TODO: showMessage
        // TODO: showDocument

        LS3P_ARCHIVE(Window)
        {
            archive
                ("workDoneProgress", work_done_progress);
        }
    };

    std::optional<Window> window;

    struct General
    {
        std::optional<core::RegularExpressionsClientCapabilities> regular_expressions;
        std::optional<core::MarkdownClientCapabilities> markdown;

        LS3P_ARCHIVE(General)
        {
            archive
                ("regularExpressions", regular_expressions)
                ("markdown", markdown);
        }
    };

    std::optional<General> general;

    std::optional<nlohmann::json> experimental;

    LS3P_ARCHIVE(ClientCapabilities)
    {
        archive
            ("workspace", workspace)
            ("textDocument", text_document)
            ("window", window)
            ("general", general)
            ("experimental", experimental);
    }
};

struct ServerCapabilities
{
    // TODO: textDocumentSync
    // TODO: completionProvider
    // TODO: hoverProvider
    // TODO: signatureHelpProvider
    // TODO: declarationProvider
    // TODO: definitionProvider
    // TODO: typeDefinitionProvider
    // TODO: implementationProvider
    // TODO: referencesProvider
    // TODO: documentHighlightProvider
    // TODO: documentSymbolProvider
    // TODO: codeActionProvider
    // TODO: codeLensProvider
    // TODO: documentLinkProvider
    // TODO: colorProvider
    // TODO: documentFormattingProvider
    // TODO: documentRangeFormattingProvider
    // TODO: documentOnTypeFormattingProvider
    // TODO: renameProvider
    // TODO: foldingRangeProvider
    // TODO: executeCommandProvider
    // TODO: selectionRangeProvider
    // TODO: linkedEditingRangeProvider
    // TODO: callHierarchyProvider
    // TODO: semanticTokensProvider
    // TODO: monikerProvider
    // TODO: workspaceSymbolProvider

    struct Workspace
    {
        std::optional<workspace::WorkspaceFoldersServerCapabilities> workspace_folders;
        std::optional<ClientCapabilities::Workspace::FileOperations> file_operations;

        LS3P_ARCHIVE(Workspace)
        {
            archive
                ("workspaceFolders", workspace_folders)
                ("fileOperations", file_operations);
        }
    };

    std::optional<Workspace> workspace;

    std::optional<nlohmann::json> experimental;

    LS3P_ARCHIVE(ServerCapabilities)
    {
        archive
            ("workspace", workspace)
            ("experimental", experimental);
    }
};

struct InitializeParams
{
    std::optional<int> process_id;

    struct ClientInfo
    {
        std::string name;
        std::optional<std::string> version;

        LS3P_ARCHIVE(ClientInfo)
        {
            archive
                ("name", name)
                ("version", version);
        }
    };

    std::optional<ClientInfo> client_info;

    std::optional<std::string> locale;

    //[[deprecated("root_uri is recommended in the LSP")]]
    std::optional<std::variant<std::string, std::monostate>> root_path;

    std::optional<nlohmann::json> initialization_options;

    ClientCapabilities capabilities;

    std::optional<core::TraceValue> trace;

    std::vector<workspace::WorkspaceFolder> workspace_folders;

    LS3P_ARCHIVE(InitializeParams)
    {
        archive
            ("processId", process_id)
            ("clientInfo", client_info)
            ("local", locale)
            ("rootPath", root_path)
            ("initializationOptions", initialization_options)
            ("capabilities", capabilities)
            ("trace", trace)
            ("workspaceFolders", workspace_folders);
    }
};

struct InitializeResult
{
    ServerCapabilities capabilities;

    struct ServerInfo
    {
        std::string name;
        std::optional<std::string> version;

        LS3P_ARCHIVE(ServerInfo)
        {
            archive
                ("name", name)
                ("version", version);
        }
    };

    ServerInfo server_info;

    LS3P_ARCHIVE(InitializeResult)
    {
        archive
            ("capabilities", capabilities)
            ("serverInfo", server_info);
    }
};

enum class InitializeErrorCode : Integer
{
    UNKNOWN_PROTOCOL_VERSION = 1
};

struct InitializeError
{
    bool retry;

    LS3P_ARCHIVE(InitializeError)
    {
        archive
            ("retry", retry);
    }
};

struct InitializedParams
{
    LS3P_ARCHIVE(InitializedParams) {}
};

}