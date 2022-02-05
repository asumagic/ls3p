#pragma once

#include <ls3p/structs/common.hpp>

namespace ls3p::structs::workspace
{

struct DidChangeWatchedFilesClientCapabilities
{
    std::optional<bool> dynamic_registration;

    LS3P_ARCHIVE(DidChangeWatchedFilesClientCapabilities)
    {
        archive
            ("dynamicRegistration", dynamic_registration);
    }
};

enum class WatchKind : UInteger
{
    CREATE = (1 << 0),
    CHANGE = (1 << 1),
    DELETE = (1 << 2)
};

struct FileSystemWatcher
{
    std::string glob_pattern;
    std::optional<UInteger> kind;

    LS3P_ARCHIVE(FileSystemWatcher)
    {
        archive
            ("globalPattern", glob_pattern)
            ("kind", kind);
    }
};

struct DidChangeWatchedFilesRegistrationOptions
{
    std::vector<FileSystemWatcher> watchers;

    LS3P_ARCHIVE(DidChangeWatchedFilesRegistrationOptions)
    {
        archive
            ("watchers", watchers);
    }
};

enum class FileChangeType
{
    CREATED = 1,
    CHANGED = 2,
    DELETED = 3
};

struct FileEvent
{
    DocumentUri uri;
    FileChangeType type;

    LS3P_ARCHIVE(FileEvent)
    {
        archive
            ("uri", uri)
            ("type", type);
    }
};

// TODO: DidChangeWatchedFilesParams

}