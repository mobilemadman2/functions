/**
 * Listing repositories from Github via Ajax with Github API
 * http://yonaba.github.io/2012/08/14/List-your-GitHub-projects-using-JavaScript-and-jQuery.md.html
 * @param username
 * @param container
 */
bmp.loadRepositories = function (username, container) {
    // If container exists
    var $container = $(container);
    if ($container.length) {
        $container.html("<span>Querying GitHub for " + username + "'s repositories...</span>");

        // Get data from Github
        $.getJSON('https://api.github.com/users/' + username + '/repos?callback=?', function (data) {
            // console.log(data.data); // raw response

            var repos = dataFilter(data.data); // JSON Parsing
            console.log(repos);
        });
    }

    // Filter with needed data only
    function dataFilter(repos) {
        var filteredRepos = [];

        $(repos).each(function () {
            filteredRepos.push({
                "id": this.id,
                "name": this.name,
                "full_name": this.full_name,
                "private": this.private,
                "description": this.description,
                "html_url": this.html_url,
                "homepage": this.homepage
            });
        });

        return filteredRepos;
    }
};
bmp.loadRepositories("phucbm", "#my-github-projects");