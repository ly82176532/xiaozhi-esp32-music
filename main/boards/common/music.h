#ifndef MUSIC_H
#define MUSIC_H

#include <string>

class Music {
public:
    virtual ~Music() = default;  // 添加虚析构函数
    
    virtual bool Download(const std::string& song_name) = 0;
    virtual bool Play() = 0;
    virtual bool Stop() = 0;
    virtual std::string GetDownloadResult() = 0;
    
    // 新增流式播放相关方法
    virtual bool StartStreaming(const std::string& music_url) = 0;
    virtual bool StopStreaming() = 0;  // 停止流式播放
    virtual size_t GetBufferSize() const = 0;
    virtual bool IsDownloading() const = 0;

// >>> xiaozhi-kugou:play_url >>>
    // 直接按音频直链播放，不经过内置曲库。
    // song_name / singer 仅用于屏幕显示；lyric_url 是可选的字幕(LRC)地址。
    virtual bool PlayUrl(const std::string& url,
                         const std::string& song_name,
                         const std::string& singer,
                         const std::string& lyric_url) = 0;
// <<< xiaozhi-kugou:play_url <<<
};

#endif // MUSIC_H 