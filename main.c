#include <stdio.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>

int main(void) {
    AVFormatContext *formatContext = NULL;

    av_register_all(); // Registrar todos os codecs e formatos do FFmpeg

    // Abrir o arquivo de vídeo
    int result = avformat_open_input(&formatContext, "amor.wmv", NULL, NULL);
    if (result < 0) {
        char errorBuffer[AV_ERROR_MAX_STRING_SIZE];
        av_strerror(result, errorBuffer, AV_ERROR_MAX_STRING_SIZE);
        printf("Erro ao abrir o arquivo: %s\n", errorBuffer);
        return 1;
    }

    // Obter informações do formato do vídeo
    result = avformat_find_stream_info(formatContext, NULL);
    if (result < 0) {
        printf("Erro ao obter informações do formato do vídeo\n");
        avformat_close_input(&formatContext);
        return 1;
    }

    // Procurar pelo stream de vídeo
    int videoStreamIndex = -1;
    for (int i = 0; i < formatContext->nb_streams; i++) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStreamIndex = i;
            break;
        }
    }

    if (videoStreamIndex == -1) {
        printf("Nenhum stream de vídeo encontrado no arquivo\n");
        avformat_close_input(&formatContext);
        return 1;
    }

    // Obter informações sobre o codec de vídeo
    AVCodecParameters *codecParameters = formatContext->streams[videoStreamIndex]->codecpar;
    AVCodec *codec = avcodec_find_decoder(codecParameters->codec_id);
    if (codec == NULL) {
        printf("Codec de vídeo não suportado\n");
        avformat_close_input(&formatContext);
        return 1;
    }

    printf("Codec de vídeo: %s\n", codec->name);

    avformat_close_input(&formatContext);

    // Código para reproduzir o vídeo usando FFmpeg vai aqui
    // ...

    return 0;
}