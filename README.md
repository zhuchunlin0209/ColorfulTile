# ColorfulTile
修改 Windows10 磁贴颜色

## 修改磁贴的API
[C# API](https://docs.microsoft.com/zh-cn/windows/uwp/design/shell/tiles-and-notifications/creating-tiles "修改磁贴的API")

但是我不会 C# , 有兴趣可以看一下

### [主要 API](https://docs.microsoft.com/zh-cn/windows/uwp/design/shell/tiles-and-notifications/primary-tile-apis "点击传送")

> ##### Checking whether the API&apos;s exist
> If your app supports older versions of Windows 10, you need to check whether these primary tile APIs are available. You do this by using ApiInformation. If the primary tile APIs aren&apos;t available, avoid executing any calls to the APIs.
> ```C#
> if (ApiInformation.IsTypePresent("Windows.UI.StartScreen.StartScreenManager")) {
>    // Primary tile API's supported!
> } else {
>    // Older version of Windows, no primary tile API's
> }
> ```
>
> ##### Check if Start supports your app
> Depending on the current Start menu, and your type of app, pinning your app to the current Start screen might not be supported. Only Desktop and Mobile support pinning the primary tile to Start. Therefore, before showing any pin UI or executing any pin code, you first need to check if your app is even supported for the current Start screen. If it&apos;s not supported, don&apos;t prompt the user to pin the tile.
> ```C#
> // Get your own app list entry
> // (which is always the first app list entry assuming you are not a multi-app package)
> AppListEntry entry = (await Package.Current.GetAppListEntriesAsync())[0];
> // Check if Start supports your app
> bool isSupported = StartScreenManager.GetDefault().SupportsAppListEntry(entry);
> ```
>
> ##### Check whether you&apos;re currently pinned
> To find out if your primary tile is currently pinned to Start, use the [ContainsAppListEntryAsync](https://docs.microsoft.com/zh-cn/uwp/api/windows.ui.startscreen.startscreenmanager#Windows_UI_StartScreen_StartScreenManager_ContainsAppListEntryAsync_Windows_ApplicationModel_Core_AppListEntry_) method.
> ```C#
> // Get your own app list entry
> AppListEntry entry = (await Package.Current.GetAppListEntriesAsync())[0];
> // Check if your app is currently pinned
> bool isPinned = await StartScreenManager.GetDefault().ContainsAppListEntryAsync(entry);
> ```
>
> ##### Pin your primary tile
> If your primary tile currently isn&apos;t pinned, and your tile is supported by Start, you might want to show a tip to users that they can pin your primary tile.
>
>> 备注
>>
>> You must call this API from a UI thread while your app is in the foreground, and you should only call this API after the user has intentionally requested the primary tile be pinned (for example, after the user clicked yes to your tip about pinning the tile).

> If the user clicks your button to pin the primary tile, you would then call the RequestAddAppListEntryAsync method to request that your tile be pinned to Start. This will display a dialog asking the user to confirm that they want your tile pinned to Start.
>
> This will return a boolean representing whether your tile is now pinned to Start. If your tile was already pinned, this will immediately return true without showing the dialog to the user. If the user clicks no on the dialog, or pinning your tile to Start isn&apos;t supported, this will return false. Otherwise, the user clicked yes and the tile was pinned, and the API will return true.
> ```C#
> // Get your own app list entry
> AppListEntry entry = (await Package.Current.GetAppListEntriesAsync())[0];
> // And pin it to Start
> bool isPinned = await StartScreenManager.GetDefault().RequestAddAppListEntryAsync(entry);
> ```

## 另外
此程序由[蓝点lilac](https://space.bilibili.com/34492771 "传送到 蓝点lilac 的 Bilibili 个人空间")的思路启发而编写

视频介绍地址 [av53445777](https://www.bilibili.com/video/av53445777 "by 蓝点lilac")

GUI 这边会尽快跟上

### 为什么要弄这个程序？
因为作者游手好闲, 手痒也想试一试

如果原作者不愿用 C++/Java 开发此程序, 请联系我及时删除

----

~~说以下话的勇气源于作者的厚颜无耻~~

~~如果喜欢, 动动你们的小手指, 戳下[关注](https://space.bilibili.com/329963941 "传送到 Bilibili")呗~~

~~别忘记 star 哟~~

[![](https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1561728135184&di=c013039d916dd8a2cfc7f3327bfd1ad4&imgtype=0&src=http%3A%2F%2Fhbimg.b0.upaiyun.com%2F7ec454481a2d8d45fcb0d51de1e6fc0438e5419f13ade-eWmT1w_fw658)](https://space.bilibili.com/329963941)

### END
