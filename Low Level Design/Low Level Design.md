## Sim U Duck App

![[Low Level Design-1766476718298.png|924x456]]

- `display()` is abstract because appearance varies for every duck subtype and there is no meaningful default implementation. Making it abstract enforces that each subclass defines its own display logic and avoids incorrect or misleading behavior in the base class