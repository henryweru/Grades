#include <microhttpd.h>
#include <stdio.h>

static int request_handler(void *cls, struct MHD_Connection *connection,
                           const char *url, const char *method,
                           const char *version, const char *upload_data,
                           size_t *upload_data_size, void **con_cls) {
    const char *response = "Hello, this is your C web server!";
    struct MHD_Response *mhd_response;
    int ret;

    // Create a response object
    mhd_response = MHD_create_response_from_data(strlen(response),
                                                 (void *)response,
                                                 MHD_NO,
                                                 MHD_NO);

    // Send the response
    ret = MHD_queue_response(connection, MHD_HTTP_OK, mhd_response);
    MHD_destroy_response(mhd_response);

    return ret;
}

int main() {
    struct MHD_Daemon *daemon;

    // Start the HTTP server on port 8080
    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, 8080, NULL, NULL,
                              &request_handler, NULL, MHD_OPTION_END);

    if (daemon == NULL) {
        fprintf(stderr, "Failed to start server\n");
        return 1;
    }

    printf("Server running on http://localhost:8080/\n");

    // Wait for the user to press Enter
    printf("Press Enter to stop the server.\n");
    getchar();

    // Stop the server
    MHD_stop_daemon(daemon);

    return 0;
}
