# Levels Ranks modules for CS2

Extra modules for [Levels Ranks](https://github.com/mrc4tt/cs2-lvl_ranks): more stats, rank
icons on the scoreboard, bonus experience and admin tools. This is a maintained fork of
[Pisex/cs2-lvl_ranks_modules](https://github.com/Pisex/cs2-lvl_ranks_modules) that keeps
working with the latest CS2 updates.

## Which download do I need?

Get the latest version from [Releases](https://github.com/mrc4tt/cs2-lvl_ranks_modules/releases).
Every module has its own file, so take only the modules you want.

| Your server | File |
|---|---|
| Linux (most servers) | `<module>-steamrt3.zip` |
| Linux, running Steam Runtime 4 | `<module>-steamrt4.zip` (the steamrt3 file works too) |
| Windows | `<module>-windows.zip` |

Not sure? Take **steamrt3**. It works on every Linux CS2 server.

The modules run on Metamod:Source 2.x, both the official
[alliedmodders](https://github.com/alliedmodders/metamod-source) version and
[mrc4tt/metamod-source](https://github.com/mrc4tt/metamod-source).

## Before you install

- [Levels Ranks](https://github.com/mrc4tt/cs2-lvl_ranks), installed and working
- [Game Utils](https://github.com/Pisex/cs2-menus) and [SQLMM](https://github.com/Pisex/mysql_mm),
  which Levels Ranks already needs
- For `LR_VIP_Multi`: the VIP core plugin
- For `LR_ExStatsGeoIP`: the free `GeoLite2-City.mmdb` database from
  [MaxMind](https://dev.maxmind.com/geoip/geolite2-free-geolocation-data)

## The modules

| Module | What it does | Config |
|---|---|---|
| `LR_ExStatsHits` | Saves hits and damage per body part | none |
| `LR_ExStatsWeapons` | Saves kills per weapon, and can give more or less experience per weapon | `exstats_weapons.ini` |
| `LR_ExStatsMaps` | Saves games, kills, deaths, rounds and bomb plants per map | none |
| `LR_ExStatsGeoIP` | Saves the country and city of each player | `GeoLite2-City.mmdb` |
| `LR_FakeRanks` | Shows the Levels Ranks rank as a rank icon on the scoreboard | `fakerank.ini` |
| `LR_UnusualKills` | Bonus experience for special kills (no scope, through smoke, in the air, ...) | `unusual_kills.ini` |
| `LR_NameReward` | More experience for players with your server name in their name | `namereward.ini` |
| `LR_VIP_Multi` | More experience for VIP players, set with the VIP feature `LrBoost` (for example `1.5`) | VIP config |
| `LR_GiveExp` | Console command to give or take experience | none |

The stats modules make their own database tables next to the Levels Ranks table, for
example `lvl_base_weapons`.

## Install

1. Download the file for each module you want (see above).
2. Extract it into your server's `game/csgo/` folder. A module adds these files, here
   `LR_FakeRanks` as an example:
   ```
   addons/levels_ranks/modules/lr_fakerank.so     (lr_fakerank.dll on Windows)
   addons/metamod/lr_fakerank.vdf
   addons/configs/levels_ranks/fakerank.ini
   ```
   Updating a module you already had? Your config files are overwritten, so keep a copy first.
3. For `LR_ExStatsGeoIP`, put `GeoLite2-City.mmdb` in `addons/configs/geoip/`.
4. Restart the server or change the map.

### Coming from the original modules

The original files went in `addons/plugins/lr/`. Delete the old file for every module you
install from here, for example `addons/plugins/lr/lr_fakerank.so`, so the module does not
load twice.

## Commands

| Console | What it does |
|---|---|
| `lr_giveexp "STEAM_1:0:12345" "100"` | Gives 100 experience (use a negative number to take it). Needs `LR_GiveExp` |
| `mm_reload_fakerank` | Loads `fakerank.ini` again without a restart. Needs `LR_FakeRanks` |

## Custom rank icons (LR_FakeRanks)

With `"Type" "0"` you can use your own icon images. The game names the image after the number
in `fakerank.ini`, without leading zeros: `"5" "1231"` shows `skillgroup1231.png`. A name like
`skillgroup0001231.png` cannot work, because CS2 reads the number as `1231`
([#9](https://github.com/Pisex/cs2-lvl_ranks_modules/issues/9)). Rename the image instead.

## What is different from the original

- Updated for the latest CS2 and Metamod:Source 2.x. The original files crash the server
  on start ([#10](https://github.com/Pisex/cs2-lvl_ranks_modules/issues/10)).
- Installs the classic Metamod way, with a `.vdf` for each module, so it loads with every
  Game Utils version.
- Comes with example configs and translations, the original had none.
- `LR_GiveExp`: only accepts real SteamIDs. Before, the command could be used to run any
  SQL on your database.
- `LR_UnusualKills`, `LR_ExStatsWeapons`, `LR_FakeRanks`: a missing or broken config no
  longer crashes the server, it prints a warning in the console.
- `LR_UnusualKills`: an unknown kill type in the config no longer corrupts memory.
- `LR_FakeRanks`: includes the fix from
  [#8](https://github.com/Pisex/cs2-lvl_ranks_modules/pull/8).
- `LR_ExStatsGeoIP`: libmaxminddb is built in, nothing to install on the server.

## Building it yourself

Most people can skip this and use the files from Releases.

Clone with `git clone --recursive`. Put [mrc4tt/hl2sdk](https://github.com/mrc4tt/hl2sdk)
(`cs2` branch), [mrc4tt/metamod-source](https://github.com/mrc4tt/metamod-source) (cloned
with `--recursive`) and
[hl2sdk-manifests](https://github.com/alliedmodders/hl2sdk-manifests) next to it, install
[AMBuild](https://github.com/alliedmodders/ambuild), then:

```bash
mkdir build && cd build
python3 ../configure.py -s cs2 --targets=x86_64 --enable-optimize \
  --hl2sdk-root=/path/to/sdks --mms_path=/path/to/metamod-source
ambuild
```

This builds all modules. Each one ends up in its own folder in `build/package/`.

Official releases are built with [cs2-build-system](https://github.com/mrc4tt/cs2-build-system).

## Credits

Made by [Pisex](https://github.com/Pisex). Uses [libmaxminddb](https://github.com/maxmind/libmaxminddb)
(Apache 2.0). Licensed under GPL.
