# Example Autosave Binder

This example adds `UDAIExample_AutoSaveBinder`, a `UGameInstanceSubsystem` that subscribes to `USaveSubsystem::OnAutoSaveRequested` and calls `AutoSave` with a simple `USaveGame` object.

How it works:
- The Save plugin’s developer settings (Project Settings → Game → DAI Save) control PIE autosave frequency.
- When the event fires, the binder rotates up to 5 slots using prefix `Auto`.

To customize:
- Replace the `USaveGame` instance with your project-specific save class.
- Adjust prefix and `MaxSlots` to your needs.
