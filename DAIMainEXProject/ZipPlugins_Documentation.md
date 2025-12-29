# ZipPlugins.bat Documentation

## Overview
The `ZipPlugins.bat` script creates individual ZIP archives for each plugin under the `Plugins` directory. It complements the existing `ZipSources.bat` script by providing full plugin archiving capabilities.

## Usage

### Basic Commands
```batch
ZipPlugins.bat                      # Create/update zips, excluding build folders
ZipPlugins.bat -clean               # Remove output folder then create
ZipPlugins.bat -includeBuild        # Include Binaries & Intermediate folders
ZipPlugins.bat -clean -includeBuild # Combined flags (order agnostic)
```

## Key Features

### Plugin Discovery
- Recursively finds all `.uplugin` files under the `Plugins` directory
- Handles various plugin folder structures:
  - Flat structure: `Plugins/DAI/DAI.uplugin`
  - Nested structure: `Plugins/DAI_AI/DAI_AI/DAI_AI.uplugin`

### Archive Creation
- Creates one ZIP per plugin named `<PluginName>.zip`
- Archives are saved to the `PluginZips` directory
- Each ZIP contains a top-level folder named after the plugin

### Build Folder Handling
- **Default behavior**: Excludes `Binaries` and `Intermediate` directories
- **With `-includeBuild`**: Includes all files including build artifacts

### Robust Processing
- Uses PowerShell with .NET ZipFile API for primary compression
- Falls back to `Compress-Archive` if primary method fails
- Provides detailed logging and error handling

## Comparison with ZipSources.bat

| Feature | ZipSources.bat | ZipPlugins.bat |
|---------|----------------|----------------|
| **Target** | Plugins with Source folders only | All plugins with .uplugin files |
| **Discovery** | Directory enumeration | Recursive .uplugin file search |
| **Output** | `<PluginName>_Source.zip` | `<PluginName>.zip` |
| **Directory** | `SourceZips/` | `PluginZips/` |
| **Build Folders** | `-excludeBuild` flag to exclude | `-includeBuild` flag to include |
| **Scope** | Source code only | Complete plugin |

## Test Results

### Plugin Coverage
- **Total plugins found**: 16
- **Plugins with Source folders**: 7 (ZipSources.bat targets)
- **All plugin types covered**: Yes (ZipPlugins.bat targets)

### File Filtering
Example filtering results:
- `DAI_Map`: 135 total files → 41 files (excluding build)
- `DAI`: 449 total files → 449 files (no build folders)
- `DAI_Traps`: 41 total files → 9 files (excluding build)

## Implementation Notes

### PowerShell Integration
The script uses PowerShell for ZIP operations with two approaches:
1. **Primary**: .NET `System.IO.Compression.ZipFile` API
2. **Fallback**: PowerShell `Compress-Archive` cmdlet

### Error Handling
- Validates `Plugins` directory existence
- Creates output directory if missing
- Handles PowerShell execution failures gracefully
- Provides detailed progress reporting

### File Exclusion Logic
```powershell
# Default: Exclude build folders
$all | Where-Object { $_.FullName -notmatch '\\Binaries\\' -and $_.FullName -notmatch '\\Intermediate\\' }

# With -includeBuild: Include all files
$all = Get-ChildItem -LiteralPath $src -Recurse -File
```

## Integration

### Git Configuration
- `PluginZips/` directory added to `.gitignore`
- Build artifacts excluded from version control

### Workflow Compatibility  
- Consistent command-line interface with `ZipSources.bat`
- Similar logging and progress reporting format
- Compatible with existing build automation scripts