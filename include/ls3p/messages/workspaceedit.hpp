#pragma once
#include <ls3p/messages/common.hpp>
#include <ls3p/messages/textedit.hpp>

namespace ls3p::messages
{

struct CreateFileOptions
{
    std::optional<bool> overwrite;
    std::optional<bool> ignore_if_exists;
};

struct CreateFile
{
    // NOTE: must assert on kind == "create"
    DocumentUri uri;
    std::optional<CreateFileOptions> options;
    std::optional<ChangeAnnotationIdentifier> annotation_id;
};

struct RenameFileOptions
{
    std::optional<bool> overwrite;
    std::optional<bool> ignore_if_exists;
};

struct RenameFile
{
    // NOTE: must assert on kind == "rename"
    DocumentUri old_uri;
    DocumentUri new_uri;
    std::optional<RenameFileOptions> options;
    std::optional<ChangeAnnotationIdentifier> annotation_id;
};

struct DeleteFileOptions
{
    std::optional<bool> overwrite;
    std::optional<bool> ignore_if_not_exists;
};

struct DeleteFile
{
    // NOTE: must assert on kind == "delete"
    DocumentUri uri;
    std::optional<DeleteFileOptions> options;
    std::optional<ChangeAnnotationIdentifier> annotation_id;
};

namespace resource_operation_kind
{

static constexpr std::string_view
    CREATE = "create",
    RENAME = "rename",
    DELETE = "delete";

}

/// \see resource_operation_kind
using ResourceOperationKind = std::string;

namespace failure_handling_kind
{

static constexpr std::string_view
    ABORT = "abort",
    TRANSACTIONAL = "transactional",
    TEXT_ONLY_TRANSACTIONAL = "textOnlyTransactional",
    UNDO = "undo";

}

/// \see failure_handling_kind
using FailureHandlingKind = std::string;

struct ChangeAnnotationSupport
{
    std::optional<bool> groups_on_labels;
};

struct WorkspaceEditClientCapabilities
{
    std::optional<bool> document_changes;
    std::optional<std::vector<ResourceOperationKind>> resource_operations;
    std::optional<std::vector<FailureHandlingKind>> failure_handling;
    std::optional<bool> normalizes_line_endings;
    std::optional<ChangeAnnotationSupport> change_annotation_support;
};

struct WorkspaceEdit
{
    std::optional<std::map<DocumentUri, std::vector<TextEdit>>> changes;

    std::vector<std::variant<TextDocumentEdit, CreateFile, RenameFile, DeleteFile>> document_changes;
};

}