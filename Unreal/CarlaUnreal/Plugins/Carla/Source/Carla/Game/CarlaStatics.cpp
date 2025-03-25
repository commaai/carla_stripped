<<<<<<< HEAD
// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma
=======
// Copyright (c) 2024 Computer Vision Center (CVC) at the Universitat Autonoma
>>>>>>> f676339c2 (added template for defaultgame.ini)
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "Carla/Game/CarlaStatics.h"
#include "Carla.h"

#include <util/ue-header-guard-begin.h>
<<<<<<< HEAD
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "Modules/ModuleManager.h"
#include "HAL/FileManagerGeneric.h"
#include <util/ue-header-guard-end.h>


TArray<FString> UCarlaStatics::GetAllPluginContentPaths()
{
  TArray<FString> OutContentDirs;
  const TArray<TSharedRef<IPlugin>> Plugins = IPluginManager::Get().GetDiscoveredPlugins();
  for (const TSharedRef<IPlugin>& Plugin : Plugins)
  {
      if (Plugin->GetLoadedFrom() == EPluginLoadedFrom::Engine)
      {
          continue;
      }

      FString ContentDir = Plugin->GetContentDir();
      if (FPaths::DirectoryExists(ContentDir))
      {
        OutContentDirs.Add(ContentDir);
      }
  }
  return OutContentDirs;
}


TArray<FString> UCarlaStatics::GetAllMapNames()
{
  TArray<FString> TmpStrList, MapNameList;
  TArray<FString> PathList;

  PathList.Add(FPaths::ProjectContentDir());
  PathList.Append(GetAllPluginContentPaths());

  for(const FString &Path : PathList) {
    if (FPaths::DirectoryExists(Path)) {
      UE_LOG(LogCarla, Log, TEXT("Path: %s"), *Path);
      IFileManager::Get().FindFilesRecursive(MapNameList, *Path, TEXT("*.umap"), true, false, false);
    }
  }

  // Filter out undesired maps
  MapNameList.RemoveAll([](const FString& Name) {
      return Name.Contains("TestMaps") || Name.Contains("OpenDriveMap") || Name.Contains("Sublevels");
  });

  for (int i = 0; i < MapNameList.Num(); i++) {
    MapNameList[i] = FPaths::GetBaseFilename(*MapNameList[i]);
  }
  return MapNameList;
}

FString UCarlaStatics::FindMapPath(const FString &MapName)
{
  TArray<FString> ContentPaths;

  ContentPaths.Add(FPaths::ProjectContentDir());
  ContentPaths.Append(GetAllPluginContentPaths());

  // Look for matching map files
  for (const FString& Path : ContentPaths)
  {
      TArray<FString> FoundFiles;
      IFileManager::Get().FindFilesRecursive(FoundFiles, *Path, TEXT("*.umap"), true, false);

      for (const FString& FilePath : FoundFiles)
      {
          FString FileName = FPaths::GetBaseFilename(FilePath); // just "MyMap", no path, no extension
          if (FileName.Equals(MapName, ESearchCase::IgnoreCase))
          {
              return FilePath; // Return the full path of the first matching map. Only one map is expected.
          }
      }
  }

  return FString();
}
=======
#include "HAL/FileManagerGeneric.h"
#include <util/ue-header-guard-end.h>

TArray<FString> UCarlaStatics::GetAllMapNames()
{
  TArray<FString> TmpStrList, MapNameList;
  IFileManager::Get().FindFilesRecursive(
      MapNameList, *FPaths::ProjectContentDir(), TEXT("*.umap"), true, false, false);
  MapNameList.RemoveAll( [](const FString &Name) { return Name.Contains("TestMaps");});
  MapNameList.RemoveAll( [](const FString &Name) { return Name.Contains("OpenDriveMap");});
  for (int i = 0; i < MapNameList.Num(); i++) {
      MapNameList[i].ParseIntoArray(TmpStrList, TEXT("Content/"), true);
      MapNameList[i] = TmpStrList[1];
      MapNameList[i] = MapNameList[i].Replace(TEXT(".umap"), TEXT(""));
      MapNameList[i] = "/Game/" + MapNameList[i];
  }
  return MapNameList;
}
>>>>>>> f676339c2 (added template for defaultgame.ini)
