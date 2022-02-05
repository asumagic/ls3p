#pragma once
#include <ls3p/structs/common.hpp>
#include <ls3p/structs/core/textedit.hpp>

namespace ls3p::structs::core
{

namespace resource_operation_kind
{

static constexpr std::string_view
    CREATE = "create",
    RENAME = "rename",
    DELETE = "delete";

}

/// \see resource_operation_kind
using ResourceOperationKind = std::string;

struct CreateFileOptions
{
    std::optional<bool> overwrite;
    std::optional<bool> ignore_if_exists;

    LS3P_ARCHIVE(CreateFileOptions)
    {
        archive
            ("overwrite", overwrite)
            ("ignoreIfExists", ignore_if_exists);
    }
};

struct CreateFile
{
    DocumentUri uri;
    std::optional<CreateFileOptions> options;
    std::optional<ChangeAnnotationIdentifier> annotation_id;

    LS3P_ARCHIVE(CreateFile)
    {
        archive
            .static_field("kind", resource_operation_kind::CREATE)
            ("uri", uri)
            ("options", options)
            ("annotationId", annotation_id);
    }
};

struct RenameFileOptions
{
    std::optional<bool> overwrite;
    std::optional<bool> ignore_if_exists;

    LS3P_ARCHIVE(RenameFileOptions)
    {
        archive
            ("overwrite", overwrite)
            ("ignoreIfExists", ignore_if_exists);
    }
};

struct RenameFile
{
    DocumentUri old_uri;
    DocumentUri new_uri;
    std::optional<RenameFileOptions> options;
    std::optional<ChangeAnnotationIdentifier> annotation_id;

    LS3P_ARCHIVE(RenameFile)
    {
        archive
            .static_field("kind", resource_operation_kind::RENAME)
            ("oldUri", old_uri)
            ("newUri", new_uri)
            ("options", options)
            ("annotaionId", annotation_id);
    }
};

struct DeleteFileOptions
{
    std::optional<bool> overwrite;
    std::optional<bool> ignore_if_not_exists;

    LS3P_ARCHIVE(DeleteFileOptions)
    {
        archive
            ("overwrite", overwrite)
            ("ignoreIfNotExists", ignore_if_not_exists);
    }
};

struct DeleteFile
{
    // NOTE: must assert on kind == "delete"
    DocumentUri uri;
    std::optional<DeleteFileOptions> options;
    std::optional<ChangeAnnotationIdentifier> annotation_id;

    LS3P_ARCHIVE(DeleteFile)
    {
        archive
            .static_field("kind", resource_operation_kind::DELETE)
            ("uri", uri)
            ("options", options)
            ("annotationId", annotation_id);
    }
};

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
    std::optional<bool> groups_on_label;

    LS3P_ARCHIVE(ChangeAnnotationSupport)
    {
        archive
            ("groupsOnLabel", groups_on_label);
    }
};

struct WorkspaceEdit
{
    struct ClientCapabilities
    {
        std::optional<bool> document_changes;
        std::optional<std::vector<ResourceOperationKind>> resource_operations;
        std::optional<std::vector<FailureHandlingKind>> failure_handling;
        std::optional<bool> normalizes_line_endings;
        std::optional<ChangeAnnotationSupport> change_annotation_support;

        LS3P_ARCHIVE(ClientCapabilities)
        {
            archive
                ("documentChanges", document_changes)
                ("resourceOperations", resource_operations)
                ("failureHandling", failure_handling)
                ("normalizesLineEndings", normalizes_line_endings)
                ("changeAnnotationSupport", change_annotation_support);
        }
    };

    std::optional<std::map<DocumentUri, std::vector<TextEdit>>> changes;

    std::vector<std::variant<TextDocumentEdit, CreateFile, RenameFile, DeleteFile>> document_changes;

    std::optional<std::map<ChangeAnnotationIdentifier, ChangeAnnotation>> change_annotations;

    LS3P_ARCHIVE(WorkspaceEdit)
    {
        archive
            ("changes", changes)
            ("documentChanges", document_changes)
            ("changeAnnotations", change_annotations);
    }
};

}