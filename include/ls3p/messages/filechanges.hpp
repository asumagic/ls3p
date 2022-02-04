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

}