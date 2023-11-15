using System.Text;

var start = DateTime.Now;
var url = "http://localhost:5000";
var minId = 1;
var maxId = 1000;
var threadCount = 100;
    
async Task<HttpResponseMessage> ExecuteQuery(int userId)
{
    var query = $"""
        Hello, {userId}!
     """;

    using var httpClientHandler = new HttpClientHandler();
    httpClientHandler.ServerCertificateCustomValidationCallback = (_, _, _, _) => true;

    using var httpClient = new HttpClient(httpClientHandler);
    
    return await httpClient.PostAsync(url, new FormUrlEncodedContent(new[]
    {
        new KeyValuePair<string, string>("Hello", Convert.ToBase64String(Encoding.UTF8.GetBytes(query))),
        new KeyValuePair<string, string>("Url", Convert.ToBase64String(Encoding.UTF8.GetBytes(url))),
    }));
}

async Task TestLogin(int userId)
{
    var message = await ExecuteQuery(userId);
    var result = await message.Content.ReadAsStringAsync();
    
    // TODO: Use result
}

var threads = new List<Thread>();

for(var i = 0; i < threadCount; i++) {
    var startIndex = minId + i;

    var thread = new Thread(() => {
        for (int j = startIndex; j < maxId; j += threadCount) {
            TestLogin(j).Wait();
        }
    });
    
    threads.Add(thread);
    thread.Start();
}

foreach (var thread in threads) {
    thread.Join();
}

Console.WriteLine($"Run time: {DateTime.Now - start}");
