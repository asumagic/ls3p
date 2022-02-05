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

}