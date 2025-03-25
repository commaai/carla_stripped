<<<<<<< HEAD
// Copyright (c) 2025 Computer Vision Center (CVC) at the Universitat Autonoma
=======
// Copyright (c) 2024 Computer Vision Center (CVC) at the Universitat Autonoma
>>>>>>> f676339c2 (added template for defaultgame.ini)
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "EditorStyleSet.h"

class FCarlaExporterCommands : public TCommands<FCarlaExporterCommands>
{
public:

  FCarlaExporterCommands()
    : TCommands<FCarlaExporterCommands>(
      TEXT("CarlaExporter"),
      NSLOCTEXT("Contexts", "CarlaExporter", "CarlaExporter Plugin"),
      NAME_None,
      FEditorStyle::GetStyleSetName())
  {
  }

  // TCommands<> interface
  virtual void RegisterCommands() override;

public:
  TSharedPtr< FUICommandInfo > PluginActionExportAll;
};
