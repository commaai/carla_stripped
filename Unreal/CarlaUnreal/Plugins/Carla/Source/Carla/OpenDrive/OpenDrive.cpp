<<<<<<< HEAD
// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma
=======
// Copyright (c) 2024 Computer Vision Center (CVC) at the Universitat Autonoma
>>>>>>> f676339c2 (added template for defaultgame.ini)
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "Carla/OpenDrive/OpenDrive.h"
#include "Carla.h"
#include "Carla/Game/CarlaGameModeBase.h"
#include "Carla/Game/CarlaStatics.h"

#include <util/ue-header-guard-begin.h>
#include "GenericPlatform/GenericPlatformProcess.h"
#include "Misc/FileHelper.h"
#include "HAL/FileManagerGeneric.h"
#include "Misc/FileHelper.h"
#include <util/ue-header-guard-end.h>

FString UOpenDrive::FindPathToXODRFile(const FString &InMapName){

  FString MapName = InMapName;

#if WITH_EDITOR
    {
<<<<<<< HEAD
=======
      // When playing in editor the map name gets an extra prefix, here we
      // remove it.
>>>>>>> f676339c2 (added template for defaultgame.ini)
      FString CorrectedMapName = MapName;
      constexpr auto PIEPrefix = TEXT("UEDPIE_0_");
      CorrectedMapName.RemoveFromStart(PIEPrefix);
      MapName = CorrectedMapName;
    }
#endif // WITH_EDITOR

<<<<<<< HEAD
  FString XODRFileName = MapName + TEXT(".xodr");
=======
  MapName += TEXT(".xodr");
>>>>>>> f676339c2 (added template for defaultgame.ini)

  const FString DefaultFilePath =
      FPaths::ProjectContentDir() +
      TEXT("Carla/Maps/OpenDrive/") +
<<<<<<< HEAD
      XODRFileName;
=======
      MapName;
>>>>>>> f676339c2 (added template for defaultgame.ini)

  auto &FileManager = IFileManager::Get();

  if (FileManager.FileExists(*DefaultFilePath))
  {
    return DefaultFilePath;
  }

  TArray<FString> FilesFound;
  FileManager.FindFilesRecursive(
      FilesFound,
      *FPaths::ProjectContentDir(),
<<<<<<< HEAD
      *XODRFileName,
=======
      *MapName,
>>>>>>> f676339c2 (added template for defaultgame.ini)
      true,
      false,
      false);

<<<<<<< HEAD
  if (FilesFound.Num() > 0)
  {
    return FilesFound[0u];
  }

  FString PluginPath = FPaths::ProjectDir() + TEXT("Plugins/") + MapName + TEXT("/Content/Maps/OpenDrive/") + XODRFileName;

  if (FileManager.FileExists(*PluginPath))
  {
    return PluginPath;
  }

  FString PluginsDir = FPaths::ProjectDir() + TEXT("Plugins/");

  TArray<FString> PluginFilesFound;
  FileManager.FindFilesRecursive(
      PluginFilesFound,
      *PluginsDir,
      *XODRFileName,
      true,
      false,
      false);

  if (PluginFilesFound.Num() > 0)
  {
    return PluginFilesFound[0u];
  }

  return FString{};
=======
  return FilesFound.Num() > 0 ? FilesFound[0u] : FString{};
>>>>>>> f676339c2 (added template for defaultgame.ini)
}

FString UOpenDrive::GetXODR(const UWorld *World)
{
  auto MapName = World->GetMapName();

<<<<<<< HEAD
=======
  // When playing in editor the map name gets an extra prefix, here we
  // remove it.
>>>>>>> f676339c2 (added template for defaultgame.ini)
  #if WITH_EDITOR
  {
    FString CorrectedMapName = MapName;
    constexpr auto PIEPrefix = TEXT("UEDPIE_0_");
    CorrectedMapName.RemoveFromStart(PIEPrefix);
    MapName = CorrectedMapName;
  }
  #endif // WITH_EDITOR

  ACarlaGameModeBase* GameMode = UCarlaStatics::GetGameMode(World);
<<<<<<< HEAD
=======

>>>>>>> f676339c2 (added template for defaultgame.ini)
  auto MapDir = GameMode->GetFullMapPath();
  const auto FolderDir = MapDir + "/OpenDrive/";
  const auto FileName = MapDir.EndsWith(MapName) ? "*" : MapName;

<<<<<<< HEAD
  TArray<FString> Files;
  IFileManager::Get().FindFilesRecursive(Files, *FolderDir, *FString(FileName + ".xodr"), true, false, false);

  if (!Files.Num())
  {
    FString PluginFolder = FPaths::ProjectDir() + TEXT("Plugins/") + MapName + TEXT("/Content/Maps/OpenDrive/");
    IFileManager::Get().FindFilesRecursive(Files, *PluginFolder, *FString(FileName + ".xodr"), true, false, false);
  }

=======
  // Find all the xodr and bin files from the map
  TArray<FString> Files;
  IFileManager::Get().FindFilesRecursive(Files, *FolderDir, *FString(FileName + ".xodr"), true, false, false);

>>>>>>> f676339c2 (added template for defaultgame.ini)
  FString Content;

  if (!Files.Num())
  {
<<<<<<< HEAD
    UE_LOG(LogCarla, Error, TEXT("No OpenDrive file found for map '%s'"), *MapName);
  }
  else if (FFileHelper::LoadFileToString(Content, *Files[0]))
  {
    UE_LOG(LogCarla, Log, TEXT("Loaded OpenDrive file '%s'"), *Files[0]);
  }
  else
  {
    UE_LOG(LogCarla, Error, TEXT("Failed to load OpenDrive file '%s'"), *Files[0]);
=======
    UE_LOG(LogTemp, Error, TEXT("Failed to find OpenDrive file for map '%s'"), *MapName);
  }
  else if (FFileHelper::LoadFileToString(Content, *Files[0]))
  {
    UE_LOG(LogTemp, Log, TEXT("Loaded OpenDrive file '%s'"), *Files[0]);
  }
  else
  {
    UE_LOG(LogTemp, Error, TEXT("Failed to load OpenDrive file '%s'"), *Files[0]);
>>>>>>> f676339c2 (added template for defaultgame.ini)
  }

  return Content;
}

FString UOpenDrive::LoadXODR(const FString &MapName)
{
  const auto FilePath = FindPathToXODRFile(MapName);

  FString Content;

  if (FilePath.IsEmpty())
  {
    UE_LOG(LogCarla, Error, TEXT("Failed to find OpenDrive file for map '%s'"), *MapName);
  }
  else if (FFileHelper::LoadFileToString(Content, *FilePath))
  {
    UE_LOG(LogCarla, Log, TEXT("Loaded OpenDrive file '%s'"), *FilePath);
  }
  else
  {
    UE_LOG(LogCarla, Error, TEXT("Failed to load OpenDrive file '%s'"), *FilePath);
  }

  return Content;
}

FString UOpenDrive::LoadXODRFullPath(const FString &FullPath)
{
  FString Content;

  if (FullPath.IsEmpty())
  {
    UE_LOG(LogCarla, Error, TEXT("Failed to find OpenDrive file for map '%s'"), *FullPath);
  }
  else if (FFileHelper::LoadFileToString(Content, *FullPath))
  {
    UE_LOG(LogCarla, Log, TEXT("Loaded OpenDrive file '%s'"), *FullPath);
  }
  else
  {
    UE_LOG(LogCarla, Error, TEXT("Failed to load OpenDrive file '%s'"), *FullPath);
  }

  return Content;
}

FString UOpenDrive::GetXODRByPath(FString XODRPath, FString MapName){

  // When playing in editor the map name gets an extra prefix, here we
  // remove it.
  #if WITH_EDITOR
  {
    FString CorrectedMapName = MapName;
    constexpr auto PIEPrefix = TEXT("UEDPIE_0_");
    CorrectedMapName.RemoveFromStart(PIEPrefix);
    MapName = CorrectedMapName;
  }
  #endif // WITH_EDITOR

  FString FileName = XODRPath.EndsWith(MapName) ? "*" : MapName;
  FString FolderDir = XODRPath;
  FolderDir.RemoveFromEnd(MapName + ".xodr");

  // Find all the xodr and bin files from the map
  TArray<FString> Files;
  IFileManager::Get().FindFilesRecursive(Files, *FolderDir, *FString(FileName + ".xodr"), true, false, false);

  FString Content;

  if (!Files.Num())
  {
    UE_LOG(LogTemp, Error, TEXT("Failed to find OpenDrive file for map '%s'"), *MapName);
  }
  else if (FFileHelper::LoadFileToString(Content, *Files[0]))
  {
    UE_LOG(LogTemp, Log, TEXT("Loaded OpenDrive file '%s'"), *Files[0]);
  }

  return Content;
}

UOpenDriveMap *UOpenDrive::LoadOpenDriveMap(const FString &MapName)
{
  UOpenDriveMap *Map = nullptr;
  auto XODRContent = LoadXODR(MapName);
  if (!XODRContent.IsEmpty())
  {
    Map = NewObject<UOpenDriveMap>();
    Map->Load(XODRContent);
  }
  return Map;
}

UOpenDriveMap *UOpenDrive::LoadCurrentOpenDriveMap(const UObject *WorldContextObject)
{
#if WITH_EDITOR

  if (WorldContextObject == nullptr)
    return nullptr;

  auto World = GEngine->GetWorldFromContextObject(
    WorldContextObject,
    EGetWorldErrorMode::LogAndReturnNull);

  if (World == nullptr)
    return nullptr;

  return LoadOpenDriveMap(World->GetMapName());
<<<<<<< HEAD

=======
  
>>>>>>> f676339c2 (added template for defaultgame.ini)
#else

  return nullptr;

#endif
}
